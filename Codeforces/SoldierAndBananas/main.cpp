#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k,n,w;

ll Solution() {
    ll sum = k*(((w+1LL)*w)/2);
    ll ans = sum - n;
    if (ans < 0)
        return 0;
    return ans;
}

int main()
{
    cin >> k >> n >> w;
    ll ans = Solution();
    if (ans == 0)
        cout << "0";
    else
        cout << ans;
    return 0;
}
