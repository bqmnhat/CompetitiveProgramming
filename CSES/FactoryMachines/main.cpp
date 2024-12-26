#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n;
ll t, k[MaxN+5], MinK;

void ReadData() {
    MinK = 1e9;
    for (int i=1; i<=n; i++) {
        cin >> k[i];
        MinK = min(MinK, k[i]);
    }
}

ll NumOfProdsMake(ll Time) {
    ll cnt = 0;
    for (int i=1; i<=n; i++)
        cnt += (Time/k[i]);
    return cnt;
}

ll BinSearch() {
    ll lo = 0, hi = t * MinK, ans = t*MinK;
    while (lo <= hi) {
        ll mid = lo + ((hi - lo) >> 1LL);
        if (NumOfProdsMake(mid) >= t) {
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
    cin >> n >> t;
    ReadData();
    cout << BinSearch();
    return 0;
}
