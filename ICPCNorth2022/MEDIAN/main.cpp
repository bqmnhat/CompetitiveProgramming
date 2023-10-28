#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long double ld;
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
int q;
rbtree a;

void Solve() {
    int cnt = 0;
    for (int i=1; i<=q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "IN") {
            int x;
            cin >> x;
            cnt++;
            a.insert(pii(x, cnt));
        }
        else if (cmd == "OUT") {
            int x;
            cin >> x;
            a.erase(a.lower_bound(pii(x, 1)));
        }
        else {
            if (a.size()&1)
                cout << a.find_by_order(a.size() / 2)->first;
            else
                cout << fixed << setprecision(2) << (ld((a.find_by_order((a.size() / 2) - 1)->first + a.find_by_order(a.size() / 2)->first))/2.0);
            cout << '\n';
        }
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
