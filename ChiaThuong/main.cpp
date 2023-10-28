#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int f[71][71],n,m;

int Solution () {
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            if (i==0)
                f[i][j] = 1;
            else if (j==0)
                f[i][j] = 0;
            else if (i<j)
                f[i][j] = f[i][i];
            else if (i>=j)
                f[i][j] = f[i][j-1] + f[i-j][j];
        }
    }
    return f[n][m];
}

int main()
{
    freopen("ChiaThuong.INP", "r", stdin);
    freopen("ChiaThuong.OUT", "w", stdout);
    cin >> n >> m;
    cout << Solution();
    return 0;
}
