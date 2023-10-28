#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[502][502];
bool dd[8000001];

void ReadData() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];
}

void Mark() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int tmp = a[i][j+1] + a[i][j-1] + a[i+1][j+1] + a[i+1][j-1] + a[i+1][j] + a[i-1][j+1] + a[i-1][j-1] + a[i-1][j];
            dd[tmp] = true;
        }
    }
}

void Solve() {
    int c;
    for (int i=1; i<=k; i++) {
        cin >> c;
        if (c > 8000000) {
            cout << 1 << ' ';
            continue;
        }
        if (dd[c])
            cout << 1 << ' ';
        else
            cout << "0 ";
    }
}

int main()
{
    cin >> n >> m >> k;
    ReadData();
    Mark();
    Solve();
    return 0;
}
