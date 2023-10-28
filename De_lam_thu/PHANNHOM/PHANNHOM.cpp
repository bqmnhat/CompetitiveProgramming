#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[100001], n, k;

void ReadData() {
    int val;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void Solve() {
    sort(a+1,a+1+n);
    int gr = 1;
    for (int i=2; i<=n; i++) {
        if (a[i] - a[i-1] > k) {
            gr++;
        }
    }
    cout << gr;
}

int main()
{
    freopen("PHANNHOM.INP", "r", stdin);
    freopen("PHANNHOM.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    Solve();
    return 0;
}
