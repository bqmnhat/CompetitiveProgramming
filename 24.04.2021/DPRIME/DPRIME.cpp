#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool Sieve[1000001];
int n;

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    int m = sqrt(1000000);
    for (int i=2; i<=m; i++) {
        if (Sieve[i] == false) {
            for (int j=i; j<=1000000/i; j++) {
                Sieve[i*j] = true;
            }
        }
    }
}

bool IsPrime(long long a) {
    if (a <= 3)
        return a>1;
    else if ((a%2 == 0) || (a%3 == 0))
        return false;
    if (a <= 1000000) {
        if (Sieve[a] == false)
            return true;
        else
            return false;
    }
    long long i=5;
    while (i*i <= a) {
        if ((a%i == 0) || (a%(i+2) == 0))
            return false;
        i+=6;
    }
    return true;
}

void Solve() {
    int k = 0;
    long long i = 1, j, p = 10;
    long long m;
    while (k<n) {
        while (Sieve[i] == true)
            i++;
        j = i + 1;
        while (Sieve[j] == true)
            j++;
        if (j>=p)
            p = p*10;
        m = i*p + j;
        if (IsPrime(m) == true)
            k++;
        i = j+1;
    }
    cout << m;
}

int main()
{
    freopen("DPRIME.INP", "r", stdin);
    freopen("DPRIME.OUT", "w", stdout);
    MakeSieve();
    cin >> n;
    Solve();
    return 0;
}
