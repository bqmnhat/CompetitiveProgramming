#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void Solve(long long n) {
    long long k = 1, d = 1,tmp;
    long long m = 9*d*k;
    while (n > m) {
        n = n - m;
        k = k + 1;
        d = d*10;
        m = 9*d*k;
    }
    tmp = d + n/k;
    if (n%k == 0)
        tmp = tmp -1;
    n = n%k;
    if (n == 0)
        n = k;
    for (int i = k; i>n; i--) {
        tmp = tmp/10;
    }
    cout << tmp%10;
}

int main()
{
    long long n;
    freopen("DAYSO.INP", "r", stdin);
    freopen("DAYSO.OUT", "w", stdout);
    cin >> n;
    Solve(n);
    return 0;
}
