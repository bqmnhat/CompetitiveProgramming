#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string a[10];
int ans = 0, res;
bool Checked[9][9];

void ReadData() {
    for (int i=1; i<=8; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }
}

void Loang(int i, int j) {
    if ((a[i][j] == '1') && (Checked[i][j] == false)) {
        res++;
        if (res > ans)
            ans = res;
        Checked[i][j] = true;
        Loang(i+1,j-1);
        Loang(i+1,j);
        Loang(i+1,j+1);
        Loang(i,j+1);
        Loang(i-1,j+1);
        Loang(i,j-1);
        Loang(i-1,j-1);
        Loang(i,j-1);
    }
}

void Solve() {
    for (int i=1; i<=8; i++) {
        for (int j=1; j<=8; j++) {
            res = 0;
            Loang(i,j);
        }
    }
}

int main()
{
    freopen("BANCO1.INP", "r", stdin);
    freopen("BANCO1.OUT", "w", stdout);
    ReadData();
    Solve();
    cout << ans;
    return 0;
}
