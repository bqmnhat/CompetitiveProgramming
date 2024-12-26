#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, k, t;
ll xs, ys, xe, ye, dirx[300], diry[300];
pii pref[MaxN+5];

void ReadData() {
    string s;
    cin >> s;
    for (int i=1; i<=n; i++) {
        pref[i].first = pref[i-1].first + dirx[s[i-1]];
        pref[i].second = pref[i-1].second + diry[s[i-1]];
    }
}

bool IsSameSign(ll a, ll b) {
    return (((a >= 0) && (b >= 0)) || ((a <= 0) && (b <= 0)));
}

bool SolveTestCase() {
    ll xDif = xe - xs, yDif = ye - ys;
    for (int i=k; i<=n; i++) {
        ll xCur = pref[i-k].first + (pref[n].first - pref[i].first),
        yCur = pref[i-k].second + (pref[n].second - pref[i].second);
        if (abs(xCur - xDif) + abs(yCur - yDif) <= k)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dirx['L'] = -1;
    dirx['R'] = 1;
    dirx['U'] = dirx['D'] = dirx['I'] = 0;
    diry['U'] = -1;
    diry['D'] = 1;
    diry['L'] = diry['R'] = diry['I'] = 0;
    cin >> t;
    while (t--) {
        cin >> n >> k >> xs >> ys >> xe >> ye;
        ReadData();
        if (SolveTestCase())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
