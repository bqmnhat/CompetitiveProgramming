#include <iostream>
#include <cstdio>
using namespace std;

long long SoDao(long long x) {
    long long a = 0;
    while (x > 0) {
        a = a*10 + x%10;
        x = x/10;
    }
    return a;
}

long long PalNum(long long n) {
    long long sd = SoDao(n);
    while (n != sd) {
        n = n + sd;
        sd = SoDao(n);
    }
    return n;
}

int main()
{
    int n;
    freopen("PALNUM.INP", "r", stdin);
    freopen("PALNUM.OUT", "w", stdout);
    cin >> n;
    cout << PalNum(n);
    return 0;
}
