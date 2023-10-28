#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int fib[47],n;

void BuildFib(int fib[]) {
    fib[1] = 1;
    fib[2] = 1;
    for (int i=3; i<=46; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int NoFib() {
    int k,d = 0;
    for (int j = 1; j<=n; j++) {
        cin >> k;
        for (int i = 1; i<=46; i++) {
            if (fib[i] == k) {
                d = d + 1;
                break;
            }
        }
    }
    return d;
}

int main()
{
    freopen("COUNT_FI.INP", "r", stdin);
    freopen("COUNT_FI.OUT", "w", stdout);
    BuildFib(fib);
    cout << NoFib();
    return 0;
}
