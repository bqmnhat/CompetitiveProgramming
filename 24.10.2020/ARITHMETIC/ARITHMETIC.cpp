#include <iostream>
#include <cstdio>
using namespace std;
long long n, a[1001];

void ReadData(int n, long long a[1001]) {
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
}

void Solve() {
    int d = 0, m = 1e9 + 7;
    while (n > 1) {
        n = n - 1;
        d = d + 1;
        for (int i = 1; i<=n; i++) {
            if (d%2 == 1)
                a[i] = ((a[i]%m) + (a[i+1]%m))%m;
            else
                a[i] = ((a[i]%m)*(a[i+1]%m))%m;
        }
    }
    cout << a[1];
}

int main()
{
    freopen("ARITHMETIC.INP", "r", stdin);
    freopen("ARITHMETIC.OUT", "w", stdout);
    cin >> n;
    ReadData(n,a);
    Solve();
    return 0;
}
