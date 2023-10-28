#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[101][101], m ,n, ans[100001], tmp = 0, l = 0;
bool b[101][101];

void ReadData() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
}

void Loang(int x,int y) {
    if ((a[x][y] == 1) && (b[x][y] == false)) {
        tmp++;
        b[x][y] = true;
        Loang(x, y+1);
        Loang(x+1,y);
    }
}

void Solve() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            tmp = 0;
            Loang(i,j);
            if (tmp > 0) {
                l++;
                ans[l] = tmp;
            }
        }
    }
    sort(ans+1,ans+1+l);
    for (int i=1; i<=l; i++) {
        cout << ans[i] << endl;
    }
}

int main()
{
    freopen("PV.INP", "r", stdin);
    freopen("PV.OUT", "w", stdout);
    cin >> m >> n;
    ReadData();
    Solve();
    return 0;
}
