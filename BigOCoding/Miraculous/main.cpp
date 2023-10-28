#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
typedef pair<int, int> pii;
int n, h, b, e, c[MaxN+1], log_2[MaxN+1], ans[MaxN+1], SpTabMin[MaxN+2][21];
vector<int> pos[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> c[i];
        SpTabMin[i][0] = c[i];
        pos[c[i]].push_back(i);
    }
}

void MakeLog2() {
    for (int i=2; i<=MaxN; i++)
        log_2[i] = log_2[i/2] + 1;
}

void MakeSpTab() {
    int step;
    for (int j=1; (1 << j) <= n; j++) {
        step = (1 << (j-1));
        for (int i=1; i + 2*step <= n+1; i++) {
            SpTabMin[i][j] = min(SpTabMin[i][j-1], SpTabMin[i+step][j-1]);
        }
    }
}

int MinQuerry(int l, int r) {
    int k = log_2[r-l+1];
    return min(SpTabMin[l][k], SpTabMin[r - (1 << k) + 1][k]);
}

int BinSearchPos(int Enzyme, int id) {
    int lo = 0, hi = pos[Enzyme].size()-1, mid, ans;
    while (lo <= hi) {
        mid = (lo + hi)/2;
        if (pos[Enzyme][mid] <= id) {
            ans = pos[Enzyme][mid];
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

void SolveTestCase() {
    memset(ans, 0, sizeof(ans));
    for (int i=1; i<=n; i++) {
        int lo = max(1, i-h+1), hi = i;
        int BestEnzyme = MinQuerry(lo, hi);
        ans[BinSearchPos(BestEnzyme, i)]++;
    }
    for (int i=b; i<=e; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

void Solve() {
    MakeLog2();
    while (cin >> n >> h >> b >> e) {
        for (int i=0; i<=MaxN; i++)
            pos[i].clear();
        ReadData();
        MakeSpTab();
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
