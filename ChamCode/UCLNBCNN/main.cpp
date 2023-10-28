#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;

ll GCD(ll a, ll b) {
    ll tmp;
    while (b != 0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

ll LCM(ll a ,ll b) {
    ll ans = (a*b)/GCD(a,b);
    return ans;
}

int main()
{
    cin >> a >> b;
    cout << GCD(a,b) << " " << LCM(a, b);
    return 0;
}
