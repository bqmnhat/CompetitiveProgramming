#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
#define MaxK 20
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int t, n, m, k;
pii bombs[MaxK+1];

void ReadData() {
    for (int i=0; i<k; i++)
        cin >> bombs[i].first >> bombs[i].second;
}

ll Solution() {
    ll ans = ((1LL*n*(1LL*n+1LL))/2)*((1LL*m*(1LL*m+1LL))/2);
    for (int i=1; i<(1LL << k); i++) {
        int tmp = i, cnt = -1, cntBits = 0;
        ll minx = n, maxx = 1, miny = m, maxy = 1;
        while (tmp > 0) {
            cnt++;
            int Bit = (tmp&1);
            if (Bit) {
                cntBits++;
                minx = min(minx, 1LL*bombs[cnt].first);
                maxx = max(maxx, 1LL*bombs[cnt].first);
                miny = min(miny, 1LL*bombs[cnt].second);
                maxy = max(maxy, 1LL*bombs[cnt].second);
            }
            tmp >>= 1LL;
        }
        ll TotalSubrecHaveBombs = minx * miny * (n - maxx + 1LL) * (m - maxy + 1LL);
        if (cntBits&1)
            ans -= TotalSubrecHaveBombs;
        else
            ans += TotalSubrecHaveBombs;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m >> k;
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
