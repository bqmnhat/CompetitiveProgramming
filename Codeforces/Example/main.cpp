#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ed '\n'

ll a,b;
ll Min = LONG_MAX, res = LONG_MAX;
//
ll sol(ll x)
{
    ll m;
    if (a % x == 0) m = x;
    else m = x - (a%x);
    return m;
}
//
void check(ll n)
{
    ll LCM = (a+n)/__gcd(a+n,b+n)*(b+n);
    //cout << n << " " << LCM << ed;
    if (LCM < Min)
    {
        Min = LCM;
        res = n;
    }
    else if (LCM == Min) res = min(res,n);
}
//
int main()
{
    cin >> a >> b;
    if (a > b) swap(a,b);
    if (b - a == 0)
    {
        cout << 1;
        return 0;
    }
    for (int i = 1; i*i <= b-a; i++)
    {
        if ((b-a) % i == 0)
        {
            check(sol(i));
            check(sol((b-a)/i));
            //cout << i << ": " << sol(i) << ed;
            //cout << (a-b)/i << ": " << sol((a-b)/i) << ed;
        }
    }
    cout << res;
    return 0;
}
