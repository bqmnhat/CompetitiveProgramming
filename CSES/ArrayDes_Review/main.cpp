#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, x[100001];
long long f[100001][101];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i];
}

int Solution() {
    long long mod = 1e9 + 7;
    if (x[1] == 0)
        for (int i=1; i<=m; i++)
            f[1][i] = 1;
    else
        f[1][x[1]] = 1;
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if ((x[i] == 0) || (j == x[i]))
                f[i][j] = ((f[i-1][j]%mod) + (f[i-1][j-1]%mod) + (f[i-1][j+1]%mod))%mod;
            else if (j != x[i])
                f[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i=1; i<=m; i++)
        ans = ((ans%mod) + (f[n][i]%mod))%mod;
    return ans;
}

int main()
{
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
