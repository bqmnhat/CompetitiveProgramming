#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int m,n,a[2000];

void ReadData(int a[], int m, int n) {
    int x = m+n;
    for (int i = 0; i<x; i++) {
        cin >> a[i];
    }
}

void Solve() {
    sort(a, a + m + n);
    for (int i = 0; i<m+n; i++) {
        cout << a[i] << " ";
    }
}

int main()
{
    freopen("SORT.INP", "r", stdin);
    freopen("SORT.OUT", "w", stdout);
    cin >> m >> n;
    ReadData(a,m,n);
    Solve();
    return 0;
}
