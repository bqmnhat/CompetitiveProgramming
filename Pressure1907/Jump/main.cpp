#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
ll x;

/*bool Check(ll steps) {
    ll tmp = (steps*(steps+1))/2;
    ll Dif = tmp - x;
    return ((tmp == x) || ((Dif >= 0) && (Dif/2 <= steps)));
}*/

ll Solution() {
    if (x == 0)
        return 0;
    x = abs(x);
    ll lo = 1, hi = x;
    ll ans = 0;
    while (lo <= hi) {
        ll mid = (lo + hi)/2;
        ll tmp = (mid*(mid+1))/2;
        if (tmp >= x) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    ll tmp = (ans*(ans+1LL))/2;
    ll dif = tmp-x;
    while (dif%2 != 0) {
        ans++;
        tmp = (ans*(ans+1LL))/2;
        dif = tmp-x;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=q; i++) {
        cin >> x;
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    Solve();
    return 0;
}
