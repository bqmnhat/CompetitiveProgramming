#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MaxN 100000
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll n, k;
ll a[MaxN+5], pref[MaxN+5];
ordered_set st;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
}

bool Check(ll val) {
    st.clear();
    ll tmp = 0;
    for (int i=0; i<=n; i++) {
        tmp += st.order_of_key(pref[i] - val);
        st.insert(pref[i]);
    }
    return (tmp <= k-1);
}

ll BinSearch() {
    ll lo = -1e14, hi = 1e14, ans = -1;
    while (lo <= hi) {
        ll mid = ((lo + hi) >> 1LL);
        if (Check(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    cout << BinSearch();
    return 0;
}
