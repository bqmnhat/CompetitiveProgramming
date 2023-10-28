#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
#define MaxVal 600005
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n;
pii st[4*MaxVal+1], a[MaxN+1], dp[MaxN+1]; // st[v].first = The maximum number of steps, st[v].second = The number of ways to get maximum steps
vector<pii> q;
vector<int> ForSort;
unordered_map<int, int> encode;
const ll Mod = 1e9 + 7;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].first >> a[i].second;
        ForSort.push_back(a[i].first);
        ForSort.push_back(a[i].second);
    }
}

void Compress() {
    sort(ForSort.begin(), ForSort.end());
    int cnt = 0;
    for (int val: ForSort) {
        if (encode.find(val) == encode.end()) {
            cnt++;
            encode[val] = cnt;
        }
    }
    for (int i=1; i<=n; i++) {
        a[i].first = encode[a[i].first];
        a[i].second = encode[a[i].second];
    }
}

pii Combine(pii a, pii b) {
    if (a.first > b.first)
        return a;
    if (a.first < b.first)
        return b;
    return (pii(a.first, (a.second + b.second)%Mod));
}

void UpdateSt(int v, int tl, int tr, int id, pii val) {
    if (tl == tr)
        st[v] = Combine(st[v], val);
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

pii GetMax(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return pii(0, 0);
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return Combine(GetMax(v*2, tl, tm, l, r), GetMax(v*2+1, tm+1, tr, l, r));
}

void Solve() {
    sort(a+1, a+1+n);
    pii ans = pii(0, 0);
    for (int i=1; i<=n; i++) {
        if ((i == 1) || (a[i].first != a[i-1].first)) {
            for (int j=i; j<=n && a[j].first == a[i].first; j++) {
                dp[j] = GetMax(1, 1, MaxVal, 1, a[j].second - 1);
                dp[j].first = dp[j].first + 1;
                if (dp[j].first == 1)
                    dp[j].second = 1;
            }
            for (int j=i; j<=n && a[j].first == a[i].first; j++)
                UpdateSt(1, 1, MaxVal, a[j].second, dp[j]);
        }
    }
    for (int i=1; i<=n; i++)
        ans.first = max(ans.first, dp[i].first);
    for (int i=1; i<=n; i++)
        if (dp[i].first == ans.first)
            ans.second = (ans.second + dp[i].second)%Mod;
    cout << ans.first << '\n' << ans.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Compress();
    Solve();
    return 0;
}
