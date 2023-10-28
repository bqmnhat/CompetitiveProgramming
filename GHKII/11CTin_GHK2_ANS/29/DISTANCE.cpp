#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ed '\n'

const ll maxn = 1e3+10;

double res = 1e18;
ll n,u,v;
ll x[maxn],y[maxn];

//
void sol()
{
    x[n+1] = x[1]; y[n+1] = y[1];
    for (int i = 1; i <= n; i++)
    {
        ll a,b,c;
        a = y[i] - y[i+1]; b = x[i+1] - x[i];
        c = - a*x[i] - b*y[i];
        double Distance = abs(a*u+b*v+c)/sqrt(a*a+b*b);
        res = min(res, Distance);
    }
    cout << fixed << setprecision(4) << res;
}
//
signed main()
{
    freopen("DISTANCE.INP","r",stdin);
    freopen("DISTANCE.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> u >> v;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    sol();
    return 0;
}
