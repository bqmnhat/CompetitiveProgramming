#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ed "\n"
#define pb push_back

const ll maxn = 1e3+1;
ll n,p,L;
ll w[maxn],v[maxn];
ll s[maxn],trace[maxn];
double f[maxn];
vector<ll> ans;
//
void read_data()
{
    cin >> n >> p >> L;
    s[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
        s[i] = w[i] + s[i-1];
    }
}
//
void sol()
{
    for (int i = 1; i <= n; i++)
    {
        ll Min = v[i];
        f[i] = 1e18;
        for (int j = i-1; j >= 0; j--)
        {
            if (s[i] - s[j] > p)
                break;
            //check();
            //f[i] = double(min(f[i],f[j] + L/double(Min)));
            //check
            {
                ll t = f[j] + L/double(Min);
                if (t < f[i])
                {
                    f[i] = t;
                    trace[i] = j;
                }
            }
            Min = min(Min,v[j]);
        }
        //cout << f[i] << " ";
    }
    //cout << ed;
    cout << fixed << setprecision(2) << f[n] << ed;
    ll id = n;
    while (id != 0)
    {
        ans.pb(id);
        id = trace[id];
    }
    for (int i = ans.size()-1; i >= 0; i--)
        cout << ans[i] << " ";
}
//
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("CARGROUP.INP", "r", stdin);
    freopen("CARGROUP.OUT", "w", stdout);
    read_data();
    sol();
    return 0;
}
