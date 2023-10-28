#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a;

ll CallCost() {
    ll ans = 25000;
    ans = ans + min(a,ll(50))*600;
    a = max(a - 50, ll(0));
    ans = ans + min(a,ll(150))*400;
    a = max(a - 150, ll(0));
    ans = ans + a*200;
    return ans;
}

int main()
{
    cin >> a;
    cout << "So tien = " << CallCost();
    return 0;
}
