#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int n;
priority_queue <pii, vector<pii>, greater<pii>> pq;

void ReadData() {
    int x;
    for (int i=1; i<=n; i++) {
        cin >> x;
        pq.push(pii(x, 0));
    }
}

ll Solution() {
    for (int i=1; i<=n-1; i++) {
        ll a,b,c,d;
        pii tmp = pq.top();
        pq.pop();
        a = tmp.first;
        b = tmp.second;
        tmp = pq.top();
        pq.pop();
        c = tmp.first;
        d = tmp.second;
        pq.push(pii(a+c, max(b+1LL, d+1LL)));
    }
    return pq.top().second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CARDGAME.INP", "r", stdin);
    freopen("CARDGAME.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
