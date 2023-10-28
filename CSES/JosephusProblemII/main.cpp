#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define MaxN 200000
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int n, k;
ordered_set Nums;

void Solve() {
    if (k == 0) {
        for (int i=1; i<=n; i++)
            cout << i << ' ';
        return;
    }
    for (int i=1; i<=n; i++)
        Nums.insert(i);
    int cnt = n, id = 0;
    while (cnt > 0) {
        id = (id + k)%cnt;
        auto it = Nums.find_by_order(id);
        cout << (*it) << ' ';
        Nums.erase(it);
        cnt--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("JPII.OUT", "w", stdout);
    cin >> n >> k;
    Solve();
    return 0;
}
