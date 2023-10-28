#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, m;
pii a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].first >> a[i].second;
}

ll Solution() {
    sort(a+1, a+1+n);
    ll ans = 0;
    for (int i=1; i<=n; i++)
        if (a[i].second > a[i-1].second)
            ans += a[i].second - a[i-1].second;
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
