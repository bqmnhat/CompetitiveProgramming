#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int x, y, n, m, a[MaxN+1], SparseTable[MaxN+1][21], log_2[MaxN+1];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> a[i];
}

void MakeLog2() {
    for (int i=2; i<=n; i++)
        log_2[i] = log_2[i/2] + 1;
}

void MakeSparse() {
    for (int i=0; i<n; i++)
        SparseTable[i][0] = a[i];
    for (int j=1; (1<<j) <= n; j++) {
        int step = 1 << (j-1);
        for (int i=0; i+2*step <= n; i++)
            SparseTable[i][j] = max(SparseTable[i][j-1], SparseTable[i+step][j-1]);
    }
}

ll MaxQuery(int l, int r) {
    int k = log_2[r-l+1];
    return (max(SparseTable[l][k], SparseTable[r - (1 << k) + 1][k]));
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=m; i++) {
        ans += MaxQuery(min(x,y), max(x,y));
        x = x+7;
        while (x >= n - 1)
            x -= (n-1);
        y = y+11;
        while (y >= n)
            y -= n;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cin >> m >> x >> y;
    MakeLog2();
    MakeSparse();
    cout << Solution();
    return 0;
}
