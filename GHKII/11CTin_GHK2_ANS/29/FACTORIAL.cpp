#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ed '\n'

const ll maxn = 1e6;

double Log[maxn+1];
ll d[maxn+1];
ll n,m;
ll Left = 1e18, Right = -1e18;
//
signed main()
{
    freopen("FACTORIAL.INP","r",stdin);
    freopen("FACTORIAL.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin  >> m >> n;
    for (int i = 1; i <= maxn/4; i++)
    {
        Log[i] = log10(i) + Log[i-1];
        d[i] = Log[i] + 1;
        if (d[i] >= m && Left == 1e18) Left = i;
        if (d[i] <= n) Right = i;
        //cout << i << " " << d[i] << ed;
    }
    cout << Left << " " << Right << ed;
    //cout << d[maxn/4];
    return 0;
}
