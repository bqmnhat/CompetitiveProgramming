#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1501][1501], valdown[1501][1501], valright[1501][1501], valcheo[1501][1501],n,m;
bool Sieve[1000001];

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i<=1000; i++) {
        if (Sieve[i] == false) {
            for (int j=i; j<=1000000/i; j++) {
                Sieve[i*j] = true;
            }
        }
    }
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
}

int LengthOfK(int k) {
    int ans=0;
    while (k>0) {
        k=k/10;
        ans++;
    }
}

void DownVal(int i, int j, int& dem) {
    if (LengthOfK(valdown[i-1][j]) < 6) {
        valdown[i][j] = valdown[i-1][j]*10 + a[i][j];
    }
    else
        valdown[i][j] = a[i][j];
    if (Sieve[valdown[i][j]] == false)
        dem++;
}

void RightVal(int i, int j, int& dem) {
    if (LengthOfK(valright[i-1][j]) < 6) {
        valright[i][j] = valright[i-1][j]*10 + a[i][j];
    }
    else
        valright[i][j] = a[i][j];
    if (Sieve[valright[i][j]] == false)
        dem++;
}

void CheoVal(int i, int j, int& dem) {
    if (LengthOfK(valcheo[i-1][j]) < 6) {
        valcheo[i][j] = valcheo[i-1][j]*10 + a[i][j];
    }
    else
        valcheo[i][j] = a[i][j];
    if (Sieve[valcheo[i][j]] == false)
        dem++;
}

int Solution() {
    int dem = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            DownVal(i,j,dem);
            RightVal(i,j,dem);
            CheoVal(i,j,dem);
        }
    }
    return dem;
}

int main()
{
    freopen("TPATH.INP", "r", stdin);
    freopen("TPATH.OUT", "w", stdout);
    cin >> n >> m;
    cout << Solution();
    return 0;
}
