#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[1501][1501];
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

void CountCost(long long k, long long &cost, int &dem) {
    if (Sieve[k] == false) {
        cost += k;
        dem++;
    }
}

void Solve() {
    int dem = 0;
    long long cost = 0, valdown, valright, valcheo;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            valdown = valright = valcheo = a[i][j];
            CountCost(a[i][j],cost,dem);
            if (a[i][j] != 0) {
                for (int d=1; d<=5; d++) {
                    if (i+d <= n) {
                        valdown = valdown*10 + a[i+d][j];
                        CountCost(valdown,cost,dem);
                    }
                    if (j+d <= m) {
                        valright = valright*10 + a[i][j+d];
                        CountCost(valright,cost,dem);
                    }
                    if ((i+d <= n) && (j+d <= m)) {
                        valcheo = valcheo*10 + a[i+d][j+d];
                        CountCost(valcheo,cost, dem);
                    }
                }
            }
        }
    }
    cout << dem << " " << cost;
}

int main()
{
    freopen("TPATH.INP", "r", stdin);
    freopen("TPATH.OUT", "w", stdout);
    cin >> n >> m;
    MakeSieve();
    ReadData();
    Solve();
    return 0;
}
