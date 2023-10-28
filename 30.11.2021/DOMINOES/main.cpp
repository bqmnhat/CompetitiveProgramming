#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, dp[100001];
pii seg[100001];
map <int, int> m;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> seg[i].first >> seg[i].second;
}

int Solution() {
    sort(seg+1, seg+1+n);
    for (int i=1; i<=n; i++) {
        if (m.find(seg[i].first) == m.end())
            dp[i] = 1;
        else
            dp[i] = m[seg[i].first] + 1;
        if (m.find(seg[i].second) == m.end())
            m[seg[i].second] = dp[i];
        else
            m[seg[i].second] = max(dp[i], m[seg[i].second]);
    }
    int ans = 0;
    for (int i=1; i<=n; i++)
        ans = max(ans, dp[i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DOMINOES.INP", "r", stdin);
    freopen("DOMINOES.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
