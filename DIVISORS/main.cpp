#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool Sieve[50000001];
int a[50000001],n;

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    int m = n/2;
    for (int i=2; i<=sqrt(m); i++) {
        if (Sieve[i] == false) {
            for (int j=i; j<=m/i; ++j) {
                Sieve[j*i] = true;
            }
        }
    }
    for (int i=2; i<=m; i++) {
        if (Sieve[i] == false) {
            a[i] = a[i-1] + 1;
        }
        else
            a[i] = a[i-1];
    }
}

int Divisors() {
   int ans = a[int(cbrt(n))];
   for (int x = 2; x<=sqrt(n); x++) {
        if (Sieve[x] == false) {
            ans = ans + (a[int(n/x)] - a[x]);
        }
   }
   return ans;
}

int main()
{
    freopen("DIVISORS.INP", "r", stdin);
    freopen("DIVISORS.OUT", "w", stdout);
    cin >> n;
    MakeSieve();
    cout << Divisors();
    return 0;
}
