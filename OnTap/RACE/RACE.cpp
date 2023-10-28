#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1001][1001], f[1002][1002];
string Dir;

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
}

void BackTrack(int &x, int y) {
    while (y > 1) {
        if (f[x-1][y-1] == f[x][y] - a[x][y]) {
            x--;
            y--;
            Dir = "D" + Dir;
        }
        else if (f[x][y-1] == f[x][y] - a[x][y]) {
            y--;
            Dir = "F" + Dir;
        }
        else {
            x++;
            y--;
            Dir = "U" + Dir;
        }
    }
}

void Solve() {
    int MaxT = 0, MaxR, MaxC;
    for (int j=1; j<=m; j++) {
        for (int i=1; i<=n; i++) {
            f[i][j] = a[i][j] + max(f[i-1][j-1], max(f[i][j-1], f[i+1][j-1]));
            if ((j == m) && (f[i][j] > MaxT)) {
                MaxT = f[i][m];
                MaxR = i;
                MaxC = j;
            }
        }
    }
    BackTrack(MaxR, MaxC);
    cout << MaxR << " " << MaxT << endl;
    cout << Dir;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("RACE.INP", "r", stdin);
    freopen("RACE.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
