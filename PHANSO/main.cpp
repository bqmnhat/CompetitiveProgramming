#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Frac{
    int t, m;
    double val;
} a[1000001];
int n;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].t;
    }
    for (int i=1; i<=n; i++) {
        cin >> a[i].m;
    }
    for (int i=1; i<=n; i++) {
        a[i].val = double(a[i].t)/double(a[i].m);
    }
}

bool CompareFrac(Frac a, Frac b) {
    if (a.val == b.val)
        return (a.t < b.t);
    return (a.val < b.val);
}

void Solve() {
    sort(a+1, a+1+n, CompareFrac);
    for (int i=1; i<=n; i++) {
        if (a[i].val != 0)
            cout << a[i].t << " ";
    }
    cout << endl;
    for (int i=1; i<=n; i++) {
        if (a[i].val != 0)
            cout << a[i].m << " ";
    }
}

int main()
{
    freopen("PHANSO.INP", "r", stdin);
    freopen("PHANSO.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
