#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[1001];

void ReadData() {
    a[0] = 0;
    for (ii=1; i<=n; i++) {
        cin >> a[i];
    }
}

void PrintMin() {
    sort(a+1,a+1+n);
    for (int i=1; i<=n; i++) {
        if (a[i] != a[i-1]) {
            cout << a[i];
        }
    }
    cout << endl;
}

void PrintMax() {
    sort(a+1,a+1+n,greater<int>());
    for (int i=1; i<=n; i++) {
        if (a[i] != a[i-1]) {
            cout << a[i];
        }
    }
    cout << endl;
}

int main()
{
    freopen("MINMAX.INP", "r", stdin);
    freopen("MINMAX.OUT", "w", stdout);
    cin >> n;
    ReadData();
    PrintMin();
    PrintMax();
    return 0;
}
