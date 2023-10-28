#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-7;
int n, k;
ll a[MaxN+5], MinVal, MaxVal;

void ReadData() {
    MinVal = 1e9;
    MaxVal = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        MinVal = min(MinVal, a[i]);
        MaxVal = max(MaxVal, a[i]);
    }
}

bool Check(ld val) {
    ld PrefSum = 0, MinPrefSumBeforeKth = 0, PrefSumBeforeKth = 0;
    for (int i=1; i<=k; i++)
        PrefSum += a[i] - val;
    if (PrefSum >= 0)
        return true;
    for (int i=k+1; i<=n; i++) {
        PrefSum += a[i] - val;
        PrefSumBeforeKth += a[i-k] - val;
        MinPrefSumBeforeKth = min(MinPrefSumBeforeKth, PrefSumBeforeKth);
        if (PrefSum - MinPrefSumBeforeKth >= 0)
            return true;
    }
    return false;
}

ld Solution() {
    ld lo = MinVal, hi = MaxVal;
    while (hi - lo > EPS) {
        ld mid = ((lo + hi)/2.0);
        if (Check(mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("rate.inp", "r", stdin);
    freopen("rate.out", "w", stdout);
    cin >> n >> k;
    ReadData();
    cout << fixed << setprecision(6) << Solution();
    return 0;
}
