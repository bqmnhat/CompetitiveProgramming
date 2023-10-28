#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef pair<int, int> pii;
int n, dp[2*MaxN+5], MaxVal, st[MaxN+5];
pii mv[MaxN+5], t[MaxN+5];
vector<int> OriTs;
map<int, int> ma;

void ReadData() {
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        cin >> mv[i].first >> mv[i].second;
        OriTs.push_back(mv[i].first);
        OriTs.push_back(mv[i].second);
    }
    sort(OriTs.begin(), OriTs.end());
    for (int i=0; i<OriTs.size(); i++) {
        if (!(ma.count(OriTs[i]))) {
            cnt++;
            ma[OriTs[i]] = cnt;
        }
    }
    MaxVal = cnt;
}

void MakeTimestamps() {
    for (int i=1; i<=n; i++) {
        t[i] = pii(ma[mv[i].second], i);
        st[i] = ma[mv[i].first];
    }
    sort(t+1, t+1+n);
}

int Solution() {
    int ans = 0;
    for (int i=1, j=1; i<=MaxVal && j<=n; i++) {
        dp[i] = dp[i-1];
        if (i < t[j].first)
            continue;
        int id = t[j].second;
        dp[i] = max(dp[i], dp[st[id]] + 1);
        ans = max(ans, dp[i]);
        j++;
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
    MakeTimestamps();
    cout << Solution();
    return 0;
}
