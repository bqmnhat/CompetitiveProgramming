#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,a[100001];

void ReadData() {
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
}

int MinCut() {
    int k = 0, m = n - 1, i = 1;
    sort(a+1,a+1+n);
    while (k + a[i] <= m-1) {
        m = m - 1;
        k = k + a[i];
        ++i;
    }
    return m;
}

int main()
{
    freopen("CHAIN.INP","r", stdin);
    freopen("CHAIN.OUT","w", stdout);
    cin >> n;
    ReadData();
    cout << MinCut();
    return 0;
}
