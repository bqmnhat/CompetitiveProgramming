#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
typedef long long ll;
int t, n;
ll a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int Check(ll k) {
    unordered_map<ll, bool> ma;
    int res = 0;
    for (int i=1; i<=n; i++) {
        if (ma.find(a[i]%k) == ma.end()) {
            res++;
            ma[a[i]%k] = 1;
        }
    }
    return res;
}

ll Solution() {
    ll lo = 2, hi = 1e18;
    while (lo <= hi) {
        ll mid = ((lo + hi) >> 1LL);
        int cnt = Check(mid);
        if (cnt == 2)
            return mid;
        else if (cnt < 2)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return 1e18;
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
