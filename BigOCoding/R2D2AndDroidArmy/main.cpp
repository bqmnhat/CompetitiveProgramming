#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxM 5
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m, k, log_2[MaxN+1];
ll a[MaxN+1][MaxM+1], SpTabMax[MaxM+1][MaxN+1][21], cnt[MaxM+1];
pii Range;

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
            SpTabMax[j][i][0] = a[i][j];
        }
    }
}

void MakeLog2() {
    for (int i=2; i<=n; i++)
        log_2[i] = log_2[i/2]+1;
}

void MakeSparseTable() {
    int step;
    for (int t=1; t<=m; t++) {
        for (int j=1; (1 << j) <= n; j++) {
            step = (1 << (j-1));
            for (int i=1; i + 2*step <= n+1; i++)
                SpTabMax[t][i][j] = max(SpTabMax[t][i][j-1], SpTabMax[t][i + step][j-1]);
        }
    }
}

ll MaxQuery(int l, int r, int t) {
    int k = log_2[r-l+1];
    return max(SpTabMax[t][l][k], SpTabMax[t][r - (1 << k) + 1][k]);
}

bool CheckSegment(int l, int r, int k) {
    ll cost = 0;
    for (int i=1; i<=m; i++)
        cost += MaxQuery(l, r, i);
    return (cost <= k);
}

pii Check(int len, int k) {
    pii ranges = pii(-1, -1);
    for (int i=1; i+len-1<=n; i++) {
        if (CheckSegment(i, i+len-1, k)) {
            ranges = pii(i, i+len-1);
            break;
        }
    }
    return ranges;
}

void Solve() {
    int lo = 1, hi = n, mid;
    while (lo <= hi) {
        mid = (lo + hi)/2;
        pii tmp = Check(mid, k);
        if (tmp.first != -1) {
            lo = mid + 1;
            Range = tmp;
        }
        else
            hi = mid-1;
    }
    for (int i=Range.first; i<=Range.second; i++) {
        for (int j=1; j<=m; j++)
            cnt[j] = max(cnt[j], a[i][j]);
    }
    for (int i=1; i<=m; i++)
        cout << cnt[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    ReadData();
    MakeLog2();
    MakeSparseTable();
    Solve();
    return 0;
}
