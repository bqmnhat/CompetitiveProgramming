#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+1;
int f[maxn];

int count1(int x)
{
    int r = 0;
    while(x != 0)
    {
        ++r;
        x /= 10;
    }
    return r;
}

signed main()
{
    freopen("FACTORIAL.inp","r",stdin);
    freopen("FACTORIAL.out","w",stdout);
    int n, m; cin >> n >> m;
    f[0] = 1;
    for(int i = 1; i < maxn; ++i)
        f[i] = f[i-1]*i;
    int r = 0, l = -1;
    for(int i = 0; i < maxn; ++i)
    {
        if(count1(f[i]) >= n && count1(f[i]) <= m && l == -1) l = i;
    }
    if(l == -1 || r == -1 || r == l) cout << 2 << " " << 1 << "\n";
    else
    cout << l << " " << l+1 << "\n";
    return 0;
}
