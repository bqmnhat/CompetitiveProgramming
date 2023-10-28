#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long t,n,a[1000001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

long long Solution() {
    sort(a+1, a+1+n);
    long long ans = 2e9;
    for (int i=2; i<=n; i++) {
        if (a[i] - a[i-1] < ans)
            ans = a[i] - a[i-1];
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        cout << Solution() << endl;
    }
}

int main()
{
    freopen("DISTANCE.INP", "r", stdin);
    freopen("DISTANCE.OUT", "w", stdout);
    cin >> t;
    Solve();
    return 0;
}
