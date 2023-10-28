#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
#define MaxM 10
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, m, trace[MaxN+5];
ll a[MaxN+5], dp[MaxN+5];
pii Light[MaxN+5];

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> Light[i].first >> Light[i].second;
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Init() {
    for (int i=1; i<=n; i++)
        dp[i] = -1;
}

int BinSearchLET(int id, ll d) {
    int lo = id, hi = n, ans = -1;
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        if (a[mid] <= d) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

int FindNxtPos(int id, int Lid) {
    int LightPos = BinSearchLET(id, a[id] + Light[Lid].second);
    int NxtDpPos = BinSearchLET(LightPos, a[LightPos] + Light[Lid].second) + 1;
    return NxtDpPos;
}

ll CalDp(int id) {
    if (id > n)
        return 0;
    if (dp[id] != -1)
        return dp[id];
    ll ans = 1e18;
    for (int i=1; i<=m; i++) {
        int NxtDpPos = FindNxtPos(id, i);
        ll tmp = Light[i].first + CalDp(NxtDpPos);
        if (tmp < ans) {
            ans = tmp;
            trace[id] = i;
        }
    }
    return dp[id] = ans;
}

void Solve() {
    sort(a+1, a+1+n);
    ll ans = CalDp(1);
    vector<pii> Path;
    int cnt = 0;
    int id = 1;
    while (id <= n) {
        int LightPos = BinSearchLET(id, a[id] + Light[trace[id]].second);
        Path.push_back(pii(LightPos, trace[id]));
        id = FindNxtPos(id, trace[id]);
        cnt++;
    }
    cout << ans << ' ' << cnt << '\n';
    sort(Path.begin(), Path.end());
    for (pii x: Path)
        cout << x.first << ' ' << x.second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CHIEUSANG.INP", "r", stdin);
    freopen("CHIEUSANG.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    Init();
    Solve();
    return 0;
}
