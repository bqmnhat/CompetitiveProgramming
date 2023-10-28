#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string si[101];
string a[101];
int m,n;

void ReadData() {
    for (int i=1; i<=m; i++) {
        cin >> si[i];
    }
    for (int i=1; i<=m; i++) {
        cin >> a[i];
    }
}

void PrintRow(int ZPre, int ZAft, int id) {
    for (int i=1; i<=ZPre; i++) {
        cout << "0";
    }
    cout << a[id];
    for (int i=1; i<=ZAft; i++) {
        cout << "0";
    }
    cout << endl;
}

void FindRow(int x) {
    int OnePre = 0, OneAft = 0, ZPre = 0, ZAft = 0, CPre, CAft;
    char Hint;
    bool AftH = false;
    for (int i=0; i<n; i++) {
        if (si[x][i] == '1') {
            if (AftH == false)
                OnePre++;
            else
                OneAft++;
        }
        else if (si[x][i] == '0') {
            if (AftH == false)
                ZPre++;
            else
                ZAft++;
        }
        else {
            Hint = si[x][i];
            AftH = true;
        }
    }
    for (int i=1; i<=m; i++) {
        AftH = false;
        CPre = 0;
        CAft = 0;
        for (int j=0; j<a[i].length(); j++) {
            if (a[i][j] == Hint) {
                AftH = true;
            }
            else if (AftH == false) {
                CPre++;
            }
            else {
                CAft++;
            }
        }
        if (AftH  == true) {
            if ((CPre == OnePre) && (CAft == OneAft)) {
                PrintRow(ZPre, ZAft, i);
                return;
            }
        }
    }
}

void Solve() {
    for (int i=1; i<=m ;i++) {
        FindRow(i);
    }
}

int main()
{
    freopen("OCHU.INP", "r", stdin);
    freopen("OCHU.OUT", "w", stdout);
    cin >> m >> n;
    ReadData();
    Solve();
    return 0;
}
