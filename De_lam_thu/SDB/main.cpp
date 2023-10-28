#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[1000001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void Solve() {
    sort(a+1,a+1+n);
    int dem = 0, ans;
    for (int i=1; i<=n; i++) {
        dem++;
        if (a[i] != a[i+1]) {
            if (dem == 1)
                ans = a[i];
            dem = 0;
        }
    }
    cout << ans;
}

int main()
{
    freopen("SDB.INP", "r", stdin);
    freopen("SDB.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
