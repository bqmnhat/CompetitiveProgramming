#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
#define MaxM 500000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> p3i;
int n, m;
ll a[MaxN+5];
bool vis[MaxM+5];
map<ll, int, greater<ll>> ma;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        ma[a[i]]++;
    }
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            ll PairSum = a[i] + a[j];
            if (vis[PairSum])
                continue;
            vis[PairSum] = true;
            ma[a[i]]--;
            ma[a[j]]--;
            if (ma[a[i]] == 0)
                ma.erase(ma.find(a[i]));
            if (ma[a[j]] == 0)
                ma.erase(ma.find(a[j]));
            int OtherVal = m - PairSum;
            auto OtherElement = ma.lower_bound(OtherVal);
            if (OtherElement != ma.end())
                ans = max(ans, PairSum + (OtherElement->first));
            ma[a[i]]++;
            ma[a[j]]++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
