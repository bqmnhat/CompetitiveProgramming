#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ed '\n'

const ll maxn = 1e4+10;

ll n, x[maxn],y[maxn];
ll res;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        res += y[i];
    }
    res \
    return 0;
}
