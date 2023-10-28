#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool Sieve[1000001];
int Prime[200000], lp = 0, n;

void MakePrime() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i<=sqrt(1000000); i++) {
        if (Sieve[i] == false)
            for (int j=i; j<=1000000/i; j++)
                Sieve[i*j] = true;
    }
    for (int i=2; i<=1000000; i++) {
        if (Sieve[i] == false) {
            lp++;
            Prime[lp] = i;
        }
    }
}

int BinSearch(int lo, int hi, int val) {
    int ans = 0;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (Prime[m] <= val) {
            ans = m;
            lo = m+1;
        }
        else
            hi = m-1;
    }
    return ans;
}

long long CalF(int x) {
    long long ans = 1, i = 2;
    while (Prime[i] <= x) {
        long long tmp = BinSearch(i,lp,2*x - Prime[i]);
        ans = ans + (tmp - i)+1;
        i++;
    }
    return ans;
}

void Solve() {
    while (cin >> n) {
        cout << CalF(n) << '\n';
    }
}

int main()
{
    freopen("GOLDBACH.INP", "r", stdin);
    freopen("GOLDBACH.OUT", "w", stdout);
    MakePrime();
    Solve();
    return 0;
}
