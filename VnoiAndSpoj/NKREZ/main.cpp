#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
#define MaxTime 30000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n;
pii rent[MaxN+5];
vector<pii> RentFinAt[MaxTime+5];
ll dp[MaxTime+5];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> rent[i].first >> rent[i].second;
        RentFinAt[rent[i].second].push_back(pii(rent[i].first, rent[i].second - rent[i].first));
    }
}

ll Solution() {
    for (int i=1; i<=MaxTime; i++) {
        dp[i] = dp[i-1];
        for (pii tmp: RentFinAt[i])
            dp[i] = max(dp[i], dp[tmp.first] + tmp.second);
    }
    return dp[MaxTime];
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
