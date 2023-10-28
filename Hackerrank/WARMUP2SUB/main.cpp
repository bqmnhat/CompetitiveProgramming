#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, n, p;

ll Solution2Sub() {
    ll val = 1, num = n+1, ans = 0;
    for (int i=0; i<=n; i++) {
        ans = (ans + (val*num)%p)%p;
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
    a = 17;
    p = 1e9 + 7;
    for (int i=1; i<=100; i++) {
        n = i;
        cout << Solution2Sub() << '\n';
    }
    return 0;
}
