#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool a[18000];

void Sieve(bool a[], int n) {
    int m = ceil(sqrt(n));
    a[1] = true;
    a[0] = true;
    for (int i = 2; i<=m; i++) {
        if (a[i] == false) {
            int j = i*i;
            while (j<=n) {
                if (a[j] == false)
                    a[j] = true;
                j = j + i;
            }
        }
    }
}

void Solve(bool a[], int n) {
    bool f = false;
    for (int i = 1; i<=int(n/2); i++) {
        if ((a[i] == false) && (a[n - i] == false)) {
            cout << i << " " << n - i << endl;
            f = true;
        }
    }
    if (f == false)
        cout << n;
}

int main()
{
    int n;
    freopen("PTSONT.INP", "r", stdin);
    freopen("PTSONT.OUT", "w", stdout);
    cin >> n;
    Sieve(a,n);
    Solve(a,n);
    return 0;
}
