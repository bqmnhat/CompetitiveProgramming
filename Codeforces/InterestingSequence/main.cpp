#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n, x;

ll HighestBitPos(ll a) {
    int ans = -1;
    while (a) {
        a >>= 1ULL;
        ans++;
    }
    return ans;
}

ll AndRange(ll x, ll y) {
    ll ans = 0;
    while (x && y) {
        ll bpx = HighestBitPos(x), bpy = HighestBitPos(y);
        if (bpx != bpy)
            break;
        ll tmp = (1LL << bpx);
        ans += tmp;
        x -= tmp;
        y -= tmp;
    }
    return ans;
}

ll Solution() {
    ll lo = n, hi = 5e18, ans = -1;
    while (lo <= hi) {
        ll mid = ((lo + hi) >> 1LL);
        ll tmp = AndRange(n, mid);
        if (tmp <= x) {
            if (tmp == x)
                ans = mid;
            hi = mid - 1LL;
        }
        else
            lo = mid + 1LL;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> x;
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
