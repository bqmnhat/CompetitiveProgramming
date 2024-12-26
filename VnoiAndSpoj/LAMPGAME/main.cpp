#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n;
ll MaxA = 0;
pii a[MaxN+5];
priority_queue<ll, vector<ll>, greater<ll>> pq;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].first;
    for (int i=1; i<=n; i++)
        cin >> a[i].second;
}

ll Solution() {
    ll ans = 0;
    sort(a+1, a+1+n);
    for (int i=1; i<=n; i++) {
        pq.push(a[i].second);
        while (a[i].first < pq.size())
            pq.pop();
    }
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
