#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50000
using namespace std;
int n, q, h[MaxN+1], STabMin[MaxN+1][21],  STabMax[MaxN+1][21], log_2[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> h[i];
        STabMin[i][0] = STabMax[i][0] = h[i];
    }
}

void MakeLog2() {
    for (int i=2; i<=n; i++)
        log_2[i] = log_2[i/2] + 1;
}

void MakeSparseTable() {
    for (int j=1; (1<<j) <= n; j++) {
        int step = (1 << (j-1));
        for (int i=1; i + 2*step <= n+1; i++) {
            STabMax[i][j] = max(STabMax[i][j-1], STabMax[i+step][j-1]);
            STabMin[i][j] = min(STabMin[i][j-1], STabMin[i+step][j-1]);
        }
    }
}

int MinQuery(int l, int r) {
    int k = log_2[r-l+1];
    return min(STabMin[l][k], STabMin[r - (1 << k) + 1][k]);
}

int MaxQuery(int l, int r) {
    int k = log_2[r-l+1];
    return max(STabMax[l][k], STabMax[r - (1 << k) + 1][k]);
}

void Solve() {
    for (int i=1; i<=q; i++) {
        int l ,r;
        cin >> l >> r;
        cout << MaxQuery(l, r) - MinQuery(l, r) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ReadData();
    MakeLog2();
    MakeSparseTable();
    Solve();
    return 0;
}
