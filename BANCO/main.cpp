#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string a[9];
int n = 8;
int MaxHor[9][9], MaxCheo1[9][9], MaxCheo2[9][9], MaxVer[9][9];

void ReadData() {
    for (int i=1; i<=8; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }
}

void Solve() {
    int MH = 0, MV = 0, MC1 = 0, MC2 = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i][j] == '1') {
                MaxHor[i][j] = MaxHor[i][j-1]+1;
                MaxVer[i][j] = MaxVer[i-1][j]+1;
                MaxCheo1[i][j] = MaxCheo1[i-1][j-1]+1;
                MaxCheo2[i][j] = MaxCheo2[i-1][j+1]+1;
                if (MaxHor[i][j] > MH) {
                    MH = MaxHor[i][j];
                }
                if (MaxVer[i][j] > MV) {
                    MV = MaxVer[i][j];
                }
                if (MaxCheo1[i][j] > MC1) {
                    MC1 = MaxCheo1[i][j];
                }
                if (MaxCheo2[i][j] > MC2) {
                    MC2 = MaxCheo2[i][j];
                }
            }
            else {
                MaxHor[i][j] = 0;
                MaxVer[i][j] = 0;
                MaxCheo1[i][j] = 0;
                MaxCheo2[i][j] = 0;
            }
        }
    }
    cout << max(max(MH, MV), max(MC1,MC2));
}

int main()
{
    freopen("BANCO.INP", "r", stdin);
    freopen("BANCO.OUT", "w", stdout);
    ReadData();
    Solve();
    return 0;
}
