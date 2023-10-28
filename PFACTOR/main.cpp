#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[10001],n;

void Factorize(int k) {
    int m=sqrt(k),i=2;
    while ((i<=m) && (k>1)) {
        while (k%i==0) {
            a[i]++;
            k=k/i;
        }
        i++;
    }
    if (k>1)
        a[k]++;
}

void Solve() {
    int dem = 0;
    for (int i=1; i<=n; i++) {
        Factorize(i);
    }
    for (int i=1; i<=n;i++) {
        if (a[i] != 0) {
            dem++;
            if (dem != 1)
                cout <<"*";
            cout << i << "^" << a[i];
        }
    }
}

int main()
{
    freopen("PFACTOR.INP", "r", stdin);
    freopen("PFACTOR.OUT", "w", stdout);
    cin >> n;
    Solve();
    return 0;
}
