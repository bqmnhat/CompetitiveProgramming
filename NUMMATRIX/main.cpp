#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[1001][1001];

void MakeMode1(int x, int y) {
    bool mode1 = true;
    for (int i = x; i<=n; i++) {
        for (int j = y+1; j<=n; j++) {
            if (a[i][j-1] + x > 2*n) {
                mode1 = false;
                a[i][j] = 2;
                a[j][i] = 2;
                continue;
            }
            if (mode1 == false) {
                x = 2;
            }
            a[i][j] = a[i][j-1] + x;
            a[j][i] = a[j-1][i] + x;
        }
    }
}

void MakeMode2(int x, int y) {
    for (int i = x; i<=n; i++) {
        for (int j = y; j<=n; j++) {
            if (a[i][j-1] + 2 > 2*n) {
                a[i][j] = 2;
                a[j][i] = 2;
                continue;
            }
            a[i][j] = a[i][j-1] + 2;
            a[j][i] = a[j][i-1] + 2;
        }
    }
}

void Solve() {
    int i = 1, j = 1;
    while (i<=n) {
        if (i*j <= 2*n) {
            a[i][j] = i*j;
            MakeMode1(i,j);
        }
        else {
            a[i][j] = a[i-1][j]%(2*n) + 2;
            MakeMode2(i,j);
        }
        i++;
        j++;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    freopen("NUMMATRIX.INP", "r", stdin);
    freopen("NUMMATRIX.OUT", "w", stdout);
    cin >> n;
    Solve();
    return 0;
}
