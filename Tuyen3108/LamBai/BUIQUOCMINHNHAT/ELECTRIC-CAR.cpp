#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200010
using namespace std;
typedef long long ll;
int m;
ll n, L, R, p[MaxN+2];

void ReadData() {
    p[0] = 0;
    p[m+1] = n+1LL;
    for (int i=1; i<=m; i++)
        cin >> p[i];
    m += 1;
}

ll Solution() {
    sort(p, p+m+1);
    int st = 0, ed = m;
    while ((st <= m) && (p[st] < L))
        st++;
    while ((ed >= 0) && (p[ed] > R))
        ed--;
    if ((p[ed] < L) || (p[st] > R))
        return min((R - p[ed]), (p[st] - L));
    ll AtSt = min((p[st] - p[st-1])/2, p[st] - L);
    ll AtEd = min((p[ed + 1] - p[ed])/2, R - p[ed]);
    ll ans = max(AtSt, AtEd);
    for (int i=st; i<ed; i++) {
        ll dist = (p[i+1] - p[i])/2;
        ans = max(ans, dist);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ELECTRIC-CAR.INP", "r", stdin);
    freopen("ELECTRIC-CAR.OUT", "w", stdout);
    cin >> n >> m >> L >> R;
    ReadData();
    cout << Solution();
    return 0;
}
