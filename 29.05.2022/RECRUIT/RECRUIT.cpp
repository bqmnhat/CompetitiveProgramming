#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef pair<int, int> pii;
int n, pref[MaxN+1], b[MaxN+1];
pii city[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> city[i].first >> city[i].second;
}

int TotalBought(int id, int& Bought) {
    int cnt = 0;
    while ((cnt < city[id].first) && (pref[id-1] + cnt + Bought <= city[id].first - cnt))
        cnt++;
    Bought+=cnt;
    return (city[id].second*cnt);
}

int Solution() {
    sort(city+1, city+1+n);
    for (int i=1; i<=n; i++)
        pref[i] = pref[i-1] + city[i].first;
    int ans = 0, Bought = 0;
    for (int i=n; i>=1; i--)
        ans += TotalBought(i, Bought);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("RECRUIT.INP", "r", stdin);
    freopen("RECRUIT.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
