#include <bits/stdc++.h>
#define int long long

using namespace std;

struct pii{
    int x, y;
};
vector<pii> a;

signed main()
{
    freopen("BUG.INP","r",stdin);
    freopen("BUG.out","w",stdout);
    int n;
    cin >> n;
    a.resize(n);
    int yMin = 1e5+10, yMax = -1e5-10;
    vector<int> r;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i].x >> a[i].y;
        yMax = max(yMax,a[i].y);
        yMin = min(a[i].y,yMin);
        r.push_back(a[i].x);
    }
    int Yaxis = (yMax+yMin)/2;
    int res = abs(Yaxis-a[0].y);
    sort(r.begin(),r.end());
    for(int i = 1; i < r.size(); ++i)
    {
        res += abs(Yaxis-a[i].y);
        res += abs(r[i]-(r[0]+i));
    }
    cout << res;
    return 0;
}
