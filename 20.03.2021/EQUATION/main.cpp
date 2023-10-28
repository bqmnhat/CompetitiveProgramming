#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool a[5001], dd[670];
int x[670], lx = 0, k;

void Sieve() {
    int m = sqrt(5000);
    a[0] = a[1] = true;
    for (int i=2; i<=m; i++) {
        if (a[i] == false) {
            for (int j=i; j<=5000/i; j++) {
                a[i*j] = true;
            }
        }
    }
}

void MakeX() {
    for (int i=1; i<=5000; i++) {
        if (a[i] == false) {
            lx++;
            x[lx] = i;
        }
    }
}

void Solve() {
    int ans = 0;
    while (cin >> k) {
        ans = 0;
        for (int i=1; i<lx; i++) {
            for (int j=i; j<=lx; j++) {
                int z = k-x[i]-x[j];
                if ((a[z] == false) && (z>=x[j])) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}

int main()
{
    freopen("EQUATION.INP", "r", stdin);
    freopen("EQUATION.OUT", "w", stdout);
    Sieve();
    MakeX();
    Solve();
    return 0;
}
