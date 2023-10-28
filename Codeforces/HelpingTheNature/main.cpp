#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int t, n;
ll a[MaxN+1], d[MaxN], changes[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<n; i++)
        d[i] = a[i+1] - a[i];
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<n; i++) {
        if (d[i] < 0) {
            changes[1] += d[i];
            changes[i+1] += -d[i];
            ans+=((-1LL)*d[i]);
        }
        else if (d[i] > 0) {
            changes[i+1] += -d[i];
            ans+=d[i];
        }
    }
    for (int i=1; i<=n; i++) {
        changes[i] += changes[i-1];
        a[i] += changes[i];
    }
    for (int i=1; i<=n; i++)
        changes[i] = 0;
    return (ans + abs(a[1]));
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        cout << Solution() << '\n';
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
