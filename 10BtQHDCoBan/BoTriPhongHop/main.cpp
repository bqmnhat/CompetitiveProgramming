#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n;
pii TimeLines[10001];
ll dp[10001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> TimeLines[i].first >> TimeLines[i].second;
}

bool MyCmpPii(pii a, pii b) {
    return (a.second < b.second);
}

ll Solution() {
    sort(TimeLines+1, TimeLines+1+n, MyCmpPii);
    for (int i=1; i<=n; i++)
        dp[i] = 1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<i; j++)
            if (TimeLines[j].second <= TimeLines[i].first)
                dp[i] = max(dp[i], dp[j] + 1);
    ll ans = 0;
    for (int i=1; i<=n; i++)
        ans = max(ans, dp[i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("11.INP", "r", stdin);
    freopen("11.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
