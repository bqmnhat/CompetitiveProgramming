#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,a[10001];

bool Factorise(int x) {
    int m = sqrt(x);
    int i = 2, d = 0;
    while ((x > 1) && (i <= m) && (d < 3)) {
        if (x%i == 0) {
            d++;
            while (x%i == 0)
                x = x/i;
        }
        i++;
    }
    if (x > 1)
        d = d + 1;
    if (d >= 3)
        return true;
    else
        return false;
}

void Solve() {
    int k, d = 1, j;
    a[1] = 30;
    for (int i = 1; i<=t; i++) {
        cin >> k;
        if (a[k] != 0)
            cout << a[k] << endl;
        else {
            j = a[d] + 1;
            while (d < k) {
                if (Factorise(j)) {
                    d = d + 1;
                    a[d] = j;
                }
                j = j + 1;
            }
            cout << a[k] << endl;
        }
    }
}

int main()
{
    freopen("TPRIMEFAC.INP", "r", stdin);
    freopen("TPRIMEFAC.OUT", "w", stdout);
    cin >> t;
    Solve();
    return 0;
}
