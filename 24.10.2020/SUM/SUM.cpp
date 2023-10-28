#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long a[1000000], b[1000000];

void Solve(long long n) {
    long long d = 0,x,k = 1;
    int m = int(sqrt(2*n));
    for (long long y = m; y>=1; y--) {
        if ((2*n) % y == 0) {
            x = 2*n/y;
            if ((x+y-1) % 2 == 0) {
                b[k] = (x+y-1)/2;
                a[k] = x-b[k];
                k = k + 1;
                d = d + 1;
            }
        }
    }
    cout << d << endl;
    for (int i = 1; i<=d; i++) {
        cout << a[i] << " " << b[i] << endl;
    }
}

int main()
{
    long long n;
    freopen("SUM.INP", "r", stdin);
    freopen("SUM.OUT", "w", stdout);
    cin >> n;
    Solve(n);
    return 0;
}
