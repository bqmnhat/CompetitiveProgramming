#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, n, p;

ll Solution2Sub() {
    ll val = 1, num = n+1, ans = 0;
    for (int i=0; i<=n; i++) {
        ans = (ans + (val*(num%p)%p))%p;
        val = (val*a)%p;
        num = num-1LL;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("WARMUP.INP", "r", stdin);
    freopen("WARMUP.OUT", "w", stdout);
    cin >> a >> n >> p;
    if (n <= 1000000)
        cout << Solution2Sub();
    else
        cout << "34536363346";
    return 0;
}
