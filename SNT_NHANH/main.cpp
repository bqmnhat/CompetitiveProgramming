#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool Sieve[1000001];

void MakeSieve() {
    int m = 1000;
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i<=m; i++) {
        if (Sieve[i] == false) {
            for (int j=i; i*j <= 1000000; j++) {
                Sieve[i*j] = true;
            }
        }
    }
}

bool IsPrime(long long n) {
    if (n <= 1000000) {
        return (Sieve[n] == false);
    }
    long long m = sqrt(n), i = 5;
    while (i<=m) {
        if (n%i == 0)
            return false;
        i += 6;
    }
    return true;
}

int main()
{
    cout << IsPrime(15485143345234242);
    return 0;
}
