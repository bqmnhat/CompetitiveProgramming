#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef pair<int, int> pii;
int n, k, h[MaxN+1], SpTMin[MaxN+2][20], SpTMax[MaxN+2][20], log_2[MaxN+1];
vector<pii> Books;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> h[i];
        SpTMax[i][0] = SpTMin[i][0] = h[i];
    }
}

void MakeLog2() {
    for (int i=2; i<=n; i++)
        log_2[i] = log_2[i/2] + 1;
}

void MakeSparseTable() {
    int step;
    for (int j=1; (1 << j) <= n; j++) {
        step = (1 << (j-1));
        for (int i=1; i+2*step <= n+1; i++) {
            SpTMin[i][j] = min(SpTMin[i][j-1], SpTMin[i+step][j-1]);
            SpTMax[i][j] = max(SpTMax[i][j-1], SpTMax[i+step][j-1]);
        }
    }
}

int MinQuery(int l, int r) {
    int k = log_2[r-l+1];
    return (min(SpTMin[l][k], SpTMin[r - (1 << k) + 1][k]));
}

int MaxQuery(int l, int r) {
    int k = log_2[r-l+1];
    return (max(SpTMax[l][k], SpTMax[r - (1 << k) + 1][k]));
}

bool CheckSegment(int l, int r, int k) {
    int tmpMax = MaxQuery(l, r), tmpMin = MinQuery(l, r);
    return ((tmpMax - tmpMin) <= k);
}

vector<pii> Check(int len, int k) {
    vector<pii> b;
    for (int i=1; i+len-1 <= n; i++) {
        if (CheckSegment(i, i+len-1, k))
            b.push_back(pii(i, i+len-1));
    }
    return b;
}

void Solve() {
    int MaxLen = 0, lo = 1, hi = n, mid;
    while (lo <= hi) {
        mid = (lo + hi)/2;
        vector<pii> tmp;
        tmp = Check(mid, k);
        if (tmp.size() != 0) {
            MaxLen = mid;
            lo = mid + 1;
            Books = tmp;
        }
        else
            hi = mid - 1;
    }
    cout << MaxLen << ' ' << Books.size() << '\n';
    for (pii x : Books)
        cout << x.first << ' ' << x.second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    MakeLog2();
    MakeSparseTable();
    Solve();
    return 0;
}
