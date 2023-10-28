#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, b[1001][1001];
string a[1001],s;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }
}

int Solution() {
    b[1][1] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if ((i==1) && (j==1))
                continue;
            if (a[i][j] == s[i+j-1])
                b[i][j] = ((b[i-1][j] % 1000003) + (b[i][j-1] % 1000003))%1000003;
            else
                b[i][j] = 0;
        }
    }
    return b[n][n];
}

int main()
{
    freopen("FGIRD.INP", "r", stdin);
    freopen("FGIRD.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cin >> s;
    s = " " + s;
    cout << Solution();
    return 0;
}
