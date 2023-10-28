#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

bool IsPrime(int a) {
    int m = sqrt(a);
    if (a <= 1)
        return false;
    for (int i = 2; i<=m; i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}

void Solve(int n) {
    for (int i = 2; i<=n; i++) {
        if (IsPrime(i))
            cout << i << " ";
    }
}

int main()
{
    freopen("PRIME_1.INP", "r", stdin);
    freopen("PRIME_1.OUT", "w", stdout);
    cin >> n;
    Solve(n);
    return 0;
}
