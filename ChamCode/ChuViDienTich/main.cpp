#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;

ll CalP(ll a, ll b) {
    ll ans = (a+b)*2;
    return ans;
}

ll CalA(ll a, ll b) {
    ll ans = a*b;
    return ans;
}

int main()
{
    cin >> a >> b;
    cout << CalP(a,b) << " " << CalA(a,b);
    return 0;
}
