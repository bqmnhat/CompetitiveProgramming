#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n,l,r,a[200001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

long long NumOfPairs() {
    sort(a+1, a+1+n);
    long long ans = 0;
    for (int i=1; i<=n; i++) {
        ans += (upper_bound(a+1, a+1+n, r - a[i]) - lower_bound(a+1, a+1+n, l - a[i]));
        if ((l <= 2*a[i]) && (r >= 2*a[i]))
            ans--;
    }
    return (ans/2);
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> l >> r;
        ReadData();
        cout << NumOfPairs() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
