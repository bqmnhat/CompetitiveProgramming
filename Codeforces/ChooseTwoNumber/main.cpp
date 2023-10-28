#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxSum 1000
using namespace std;
int n, m, a[MaxN+1], b[MaxN+1];
bool marka[MaxSum+1], markb[MaxSum+1];

void ReadData() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        marka[a[i]] = true;
    }
    cin >> m;
    for (int j=1; j<=m; j++) {
        cin >> b[j];
        markb[b[j]] = true;
    }
}

void Solve() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if ((!marka[a[i] + b[j]]) && (!markb[a[i] + b[j]])) {
                cout << a[i] << ' ' << b[j];
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ReadData();
    Solve();
    return 0;
}
