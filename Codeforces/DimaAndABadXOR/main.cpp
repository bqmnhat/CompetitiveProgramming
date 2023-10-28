#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,a[501][501];

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
}

void Solve() {
    int XOR = 0;
    for (int i=1; i<=n; i++)
        XOR = (XOR^a[i][1]);
    if (XOR > 0) {
        cout << "TAK" << '\n';
        for (int i=1; i<=n; i++)
            cout << 1 << ' ';
        return;
    }
    int DifferIDI = -1, DifferIDJ = -1;
    for (int i=1; i<=n; i++) {
        for (int j=2; j<=m; j++) {
            if (a[i][j] != a[i][1]) {
                DifferIDI = i;
                DifferIDJ = j;
                break;
            }
        }
    }
    if (DifferIDI == -1) {
        cout << "NIE";
        return;
    }
    cout << "TAK" << '\n';
    for (int i=1; i<=n; i++) {
        if (DifferIDI == i)
            cout << DifferIDJ << ' ';
        else
            cout << 1 << ' ';
    }
}

int main()
{
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
