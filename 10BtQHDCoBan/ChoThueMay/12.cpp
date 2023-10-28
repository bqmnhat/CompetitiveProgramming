#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n;
pii TimeLines[10001];
ll dp[10001], c[10001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> TimeLines[i].second >> TimeLines[i].first >> c[i];
}

ll Solution() {
    ll ans = 0;
    sort(TimeLines+1, TimeLines+1+n);
    for (int i=1; i<=n; i++) {
        dp[i] = c[i];
        for (int j=1; j<i; j++) {
            if (TimeLines[j].first <= TimeLines[i].second)
                dp[i] = max(dp[i], dp[j] + c[i]);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("12.INP", "r", stdin);
    freopen("12.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
