#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,a[100],b[100];

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[j];
        }
        sort(a+1,a+1+n);
        b[i] = a[(n+1)/2];
    }
}

int main()
{
    freopen("TRUNGVI.INP", "r", stdin);
    freopen("TRUNGVI.OUT", "w", stdout);
    cin >> n;
    ReadData();
    sort(b+1,b+1+n);
    cout << b[(n+1)/2];
    return 0;
}
