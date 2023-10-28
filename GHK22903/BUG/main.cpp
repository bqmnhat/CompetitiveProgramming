#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, cnt[2*MaxN+5];
ll MinX = 1e18, MaxX = 0;
pii a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].first >> a[i].second;
        MinX = min(MinX, a[i].first);
        MaxX = max(MaxX, a[i].first);
        cnt[a[i].second + MaxN]++;
    }
}

bool CmpPiiX(pii a, pii b) {
    if (a.first == b.first)
        return (a.second < b.second);
    return (a.first < b.first);
}

bool CmpPiiY(pii a, pii b) {
    return (a.second < b.second);
}

ll Solution() {
    sort(a+1, a+1+n, CmpPiiY);
    ll y;
    int mid = (n - 1)/2 + 1;
    if (n % 2 == 0)
        y = (a[mid].second + a[mid+1].second)/2;
    else
        y = a[mid].second;
    sort(a+1, a+1+n, CmpPiiX);
    /*ll Sumy = 0;
    for (int i=1; i<=n; i++)
        Sumy += a[i].second;
    ll yAvg = Sumy/(1LL*n);*/

    ll ans = 1e18;
    for (ll x = -10000; x <= 10000; x++) {
        ll tmpans = 0;
        for (ll i=1; i<=n; i++)
            tmpans += abs(a[i].first - (x + i - 1LL)) + abs(a[i].second - y);
        ans = min(ans, tmpans);
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
