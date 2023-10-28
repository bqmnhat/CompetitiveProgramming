#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxMoves 4e9
using namespace std;
typedef long long ll;
int n;
struct Square {
    ll xl, yb, xr, yt;
} a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].xl >> a[i].yb >> a[i].xr >> a[i].yt;
}

bool CheckCollapsed(ll mvs) {
    ll MaxXl = -2e9, MinXr = 2e9, MaxYb = -2e9, MinYt = 2e9; // MaxXl < MinXr && MaxYb < MinYt
    for (int i=1; i<=n; i++) {
        MaxXl = max(MaxXl, a[i].xl - mvs);
        MinXr = min(MinXr, a[i].xr + mvs);
        MaxYb = max(MaxYb, a[i].yb - mvs);
        MinYt = min(MinYt, a[i].yt + mvs);
    }
    return ((MaxXl < MinXr) && (MaxYb < MinYt));
}

ll BinSearch() {
    ll lo = 0, hi = MaxMoves, ans = -1;
    while (lo <= hi) {
        ll mid = ((lo + hi) >> 1LL);
        if (CheckCollapsed(mid)) {
            ans = mid;
            hi = mid - 1LL;
        }
        else
            lo = mid + 1LL;
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
    cout << BinSearch();
    return 0;
}
