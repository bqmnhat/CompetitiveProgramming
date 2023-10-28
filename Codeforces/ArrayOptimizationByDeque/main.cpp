#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll, ll> node;
typedef tree<node, null_type, less<node>,rb_tree_tag, tree_order_statistics_node_update> RBSet;
int t,n;
ll a[200001];

ll SolveTestCases() {
    ll ans = 0;
    RBSet o_set;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        ll Smaller = o_set.order_of_key(node(a[i], 0));
        ll Larger = i - o_set.order_of_key(node(a[i], n)) - 1;
        ans = ans + min(Smaller, Larger);
        o_set.insert(node(a[i],i));
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << SolveTestCases() << '\n';
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
