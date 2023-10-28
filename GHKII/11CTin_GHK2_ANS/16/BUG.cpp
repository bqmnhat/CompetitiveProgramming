#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n;
pii a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].first >> a[i].second;
}

ll Solution() {
    sort(a+1, a+1+n);
    ll YSum = 0;
    for (int i=1; i<=n; i++)
        YSum += a[i].second;
    ll Yavg1 = ((YSum-1LL)/(1LL*n) + 1LL);
    ll Yavg2 = YSum/n;
    ll ans = 1e18;
    for (int i=1; i<=n; i++) {
        int cnt = 0;
        ll ans1 = 0, ans2 = 0;
        for (int j=i; j>=1; j--) {
            ans1 += abs(Yavg1 - a[j].second) + abs(a[i].first-cnt - a[j].first);
            ans2 += abs(Yavg2 - a[j].second) + abs(a[i].first-cnt - a[j].first);
            cnt++;
        }
        cnt = 1;
        for (int j=i+1; j<=n; j++) {
            ans1 += abs(Yavg1 - a[j].second) + abs(a[i].first+cnt - a[j].first);
            ans2 += abs(Yavg2 - a[j].second) + abs(a[i].first+cnt - a[j].first);
            cnt++;
        }
        ans = min(ans, min(ans1, ans2));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BUG.INP", "r", stdin);
    freopen("BUG.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
