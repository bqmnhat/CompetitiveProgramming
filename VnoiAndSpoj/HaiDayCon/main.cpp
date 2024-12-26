#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int n, k;
ll pref[MaxN+5], MinAt[MaxN+5], MaxAt[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++) {
        ll val;
        cin >> val;
        pref[i] = pref[i-1] + val;
    }
}

ll Solution() {
    ll Min = 1e18, Max = 0;
    ll ans = 0;
    for (int i=k; i<=n; i++) {
        ll SumVal = pref[i] - pref[i-k];
        if (i >= 2*k)
            ans = max(ans, max(abs(SumVal - MinAt[i-k]), abs(SumVal - MaxAt[i-k])));
        Min = min(SumVal, Min);
        Max = max(SumVal, Max);
        MinAt[i] = Min;
        MaxAt[i] = Max;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    cout << Solution();
    return 0;
}
