#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, a, b;
ll MaxDist = 0;
pii p[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> p[i].first >> p[i].second;
        MaxDist = max(MaxDist, p[i].first);
    }
}

bool CheckDist(ll dist) {
    int i = 1, j = 1, curCnt1 = 0, curCnt2 = 0;
    if (p[1].second == 1)
            curCnt1++;
        else
            curCnt2++;
    while (i <= n) {
        j = max(i, j);
        while ((j+1 <= n) && (p[j+1].first - p[i].first <= dist)) {
            j++;
            if (p[j].second == 1)
                curCnt1++;
            else
                curCnt2++;
        }
        if ((curCnt1 >= a) && (curCnt2 >= b))
            return true;
        if (p[i].second == 1)
            curCnt1--;
        else
            curCnt2--;
        i++;
    }
    return ((curCnt1 >= a) && (curCnt2 >= b));
}

ll BinsearchDist() {
    ll lo = 1, hi = MaxDist, ans = -1;
    while (lo <= hi) {
        ll mid = ((lo + hi) >> 1LL);
        if (CheckDist(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

ll Solution() {
    sort(p+1, p+1+n);
    ll res = BinsearchDist();
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b;
    ReadData();
    cout << Solution();
    return 0;
}
