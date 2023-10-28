#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int L, n, a[100001], sum = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

ll Solution() {
    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<>> pq;
    for (int i=1; i<=n; i++)
        pq.push(a[i]);
    if (L - sum > 0)
        pq.push(L - sum);
    while (pq.size() > 1) {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PARTITION.INP", "r", stdin);
    freopen("PARTITION.OUT", "w", stdout);
    cin >> L >> n;
    ReadData();
    cout << Solution();
    return 0;
}
