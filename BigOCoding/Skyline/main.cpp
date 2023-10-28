#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
int n;
ll c[2*MaxN+5][MaxN+5];
const ll Mod = 1000000;

void CalC() {
    c[0][0] = 1;
    for (int i=1; i<=2*MaxN; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j=1; j<=MaxN; j++)
            c[i][j] = (c[i-1][j-1] + c[i-1][j])%Mod;
    }
}

void Solve() {
    while ((cin >> n) && (n != 0))
        cout << (c[2*n][n] - c[2*n][n-1] + Mod*Mod)%Mod << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    CalC();
    Solve();
    return 0;
}
