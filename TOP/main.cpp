#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m, h[1001][71];
bool b[1001][71], marker;

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> h[i][j];
        }
    }
}

void CheckTop(int x, int y) {
    b[x][y] = true;
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            if ((i!=0) or (j!=0)) {
                if (h[x+i][y+j] > h[x][y]) {
                    marker = false;
                }
                else if ((h[x+i][y+j] == h[x][y]) && (b[x+i][y+j] == false)) {
                    CheckTop(x+i, y+j);
                }
            }
        }
    }
}

void Solve() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            marker = true;
            if ((b[i][j] == false) && (h[i][j] != 0))
                CheckTop(i,j);
            else
                marker = false;
            if (marker == true) {
                ans++;
            }
        }
    }
    cout << ans;
}

int main()
{
    freopen("TOP.INP", "r", stdin);
    freopen("TOP.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
