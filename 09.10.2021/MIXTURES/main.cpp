#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, t;
long long a[101], cd[101], f[101][101];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void MakeCD() {
    for (int i=1; i<=n; i++)
        cd[i] = cd[i-1] + a[i];
}

long long Solution() {
    for (int i=n-1; i>=1; i--) {
        for (int j=i+1; j<=n; j++) {
            long long Min = 1e18;
            for (int k=i; k<j; k++) {
                long long tmp = f[i][k] + f[k+1][j] + ((cd[k] - cd[i-1])%100)*((cd[j] - cd[k])%100);
                if (tmp < Min)
                    Min = tmp;
            }
            f[i][j] = Min;
        }
    }
    return f[1][n];
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        MakeCD();
        cout << Solution() << '\n';
    }
}

int main()
{
    freopen("MIXTURES.INP", "r", stdin);
    freopen("MIXTURES.OUT", "w", stdout);
    cin >> t;
    Solve();
    return 0;
}
