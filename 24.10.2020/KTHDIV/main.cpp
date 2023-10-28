#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int NOfFact(long long n) {
    int i = 2, m = int(sqrt(n));
    int tmp = 1;
    while ((i<=m) && (n>1)) {
        int d = 0;
        while (n % i == 0) {
            n = n / i;
            d = d + 1;
        }
        tmp = tmp * (d + 1);
        i = i + 1;
    }
    if (n > 1)
        tmp = tmp * 2;
    return tmp;
}

long long KthFact(long long n, int k) {
    int m = int(sqrt(n));
    long long x = NOfFact(n), d = 0;
    if (k > x)
        return -1;
    for (int i = 1; i<=m; i++) {
        if (n%i == 0) {
            d = d + 1;
            if (x-d+1 == k)
                return n/i;
            if (d == k)
                return i;
        }
    }
}

int main()
{
    long long n;
    int k;
    freopen("KTHDIV.INP", "r", stdin);
    freopen("KTHDIV.OUT", "w", stdout);
    cin >> n >> k;
    cout << KthFact(n,k);
    return 0;
}
