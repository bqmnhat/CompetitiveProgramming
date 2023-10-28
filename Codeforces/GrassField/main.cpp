#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, a[3][3];

void ReadData() {
    for (int i=1; i<=2; i++)
        for (int j=1; j<=2; j++)
            cin >> a[i][j];
}

int Solution() {
    bool All = true, None = true;
    int CntRow = 0, CntCol = 0;
    for (int i=1; i<=2; i++) {
        for (int j=1; j<=2; j++) {
            if (a[i][j] == 0)
                All = false;
            else
                None = false;
        }
    }
    if (None)
        return 0;
    else if (All)
        return 2;
    else
        return 1;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
