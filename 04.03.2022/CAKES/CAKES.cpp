#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, T;
priority_queue <ll> pq;

int Solution() {
    int ans = 0, x, t;
    ll TtTimeSpent = 0;
    for (int i=1; i<=n; i++) {
        cin >> x >> t;
        TtTimeSpent += t*1LL;
        pq.push(t);
        while ((!pq.empty()) && (TtTimeSpent + 1LL*x > T)) {
            TtTimeSpent -= pq.top();
            pq.pop();
        }
        ans = max(ans, (int)pq.size());
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CAKES.INP", "r", stdin);
    freopen("CAKES.OUT", "w", stdout);
    cin >> n >> T;
    cout << Solution();
    return 0;
}
