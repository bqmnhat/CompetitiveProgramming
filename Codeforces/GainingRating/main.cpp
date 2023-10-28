#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int t, n;
ll x, y, a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    sort(a+1, a+1+n);
    ll OriX = x;
    ll ptr = 1, change;
    ll tmp = x - a[1] + 1LL, ans = 0;
    if (tmp < 0)
        return -1;
    while ((x < y) && (ptr <= n)) {
        if ((ptr == 1) || ((ptr > 1) && (a[ptr] - a[ptr-1] <= tmp))) {
            ans++;
            ptr++;
            x++;
        }
        else {
            cout << "ptr " << ptr << '\n';
            change = 2*ptr-1LL*n-2;
            cout << "change " << change << '\n';
            if (change < 0)
                return -1;
            ll k = (a[ptr] - a[ptr-1] - tmp);
            cout << "k " << k << '\n';
            ll Shortcut = (k-1LL)/change;
            cout << "Shortcut " << Shortcut << '\n';
            ans += (Shortcut + 1LL)*n + 1LL;
            cout << "ans " << ans << '\n';
            x += Shortcut*change + ptr - 1LL;
            cout << "x " << x << '\n';
            tmp = x - a[1] + 1LL;
            cout << "tmp " << tmp << '\n';
            cout << "...........................\n";
        }
    }
    ll MoreRound = ((y-x)/change);
    ans += MoreRound;
    x += MoreRound*n;
    ans += (y - x);
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> x >> y;
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    cin >> t;
    Solve();
    return 0;
}
