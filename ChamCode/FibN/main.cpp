#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

long long FibN(long long n) {
    long long f1 = 1, f2 = 1, f3;
    if (n <= 2)
        return 1;
    for (int i=3; i<=n; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}

int main()
{
    cin >> n;
    cout << FibN(n);
    return 0;
}
