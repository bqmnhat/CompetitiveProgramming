#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
typedef long long ll;
int n;
priority_queue<ll, vector<ll>, greater<ll>> pq;

void ReadData() {
    while (!pq.empty())
        pq.pop();
    for (int i=1; i<=n; i++) {
        ll ai;
        cin >> ai;
        pq.push(ai);
    }
}

ll Solution() {
    ll ans = 0;
    while (pq.size() > 1) {
        ll sum = pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();
        ans += sum;
        pq.push(sum);
    }
    return ans;
}

void Solve() {
    while ((cin >> n) && (n != 0)) {
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
