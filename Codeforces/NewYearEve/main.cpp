#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;

int MaximumOnBit(ll n) {
    int ans = 0, i = 0;
    while (n > 0) {
        int tmp = (n&1LL);
        n = (n>>1LL);
        if (tmp == 1)
            ans = i;
        i++;
    }
    return ans;
}

long long Solution() {
    if (k == 1)
        return n;
    ll p = MaximumOnBit(n);
    ll ans = ((1LL<<p)^((1LL<<p)-1LL));
    return ans;
}

int main()
{
    cin >> n >> k;
    cout << Solution();
    return 0;
}
