#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n, k;
ll a[MaxN+5], Sum = 0, Max = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        Sum += a[i];
        Max = max(Max, a[i]);
    }
}

bool Check(ll MaxSum) {
    ll CurSum = 0;
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (CurSum + a[i] > MaxSum) {
            if (CurSum == 0)
                return false;
            cnt++;
            CurSum = 0;
        }
        CurSum += a[i];
    }
    if (CurSum > 0)
        cnt++;
    return (cnt <= k);
}

ll Solution() {
    ll lo = Max, hi = Sum, ans = -1;
    while (lo <= hi) {
        ll mid = (lo + hi)/2;
        if (Check(mid)) {
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
    cin >> n >> k;
    ReadData();
    cout << Solution();
    return 0;
}
