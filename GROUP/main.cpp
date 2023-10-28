#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[202], b[202], n, m;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

int MinCost() {
    int tmp;
    for (int i=1; i<=n; i++) {
        b[i] = a[n] - a[i];
    }
    for (int g=2; g<=m; g++) {
        for (int i=1; i<=n; i++) {
            for (int j=i; j<=n; j++) {
                tmp = (a[j] - a[i]) + b[j+1];
                if (tmp<b[i]) {
                    b[i] = tmp;
                }
            }
        }
    }
    return b[1];
}

int main()
{
    freopen("GROUP.INP", "r", stdin);
    freopen("GROUP.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    sort(a+1,a+1+n);
    cout << MinCost();
    return 0;
}
