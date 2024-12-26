#include <iostream>
#include <bits/stdc++.h>
#define MaxM 300000
using namespace std;
typedef long long ll;
int m;
ll c[MaxM+5], n, MaxC = 0;

void ReadData() {
    for (int i=1; i<=m; i++) {
        cin >> c[i];
        MaxC += c[i];
    }
}

bool Check(ll val) {
    ll cnt = 0;
    for (int i=1; i<=m; i++)
        cnt += ((c[i]-1LL)/val) + 1LL;
    return (cnt <= n);
}

ll Solution() {
    ll ans = n, lo = 0, hi = MaxC;
    while (lo <= hi) {
        ll mid = ((lo + hi) >> 1LL);
        if (Check(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
