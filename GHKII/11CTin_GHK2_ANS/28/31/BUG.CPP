#include <bits/stdc++.h>
using namespace std;

int ymn = 1e5+10; int ymx = -1e5-10;
struct point
{
    int x,y;
};

int fa(int sol, point b[10001], vector<int> r, int ax)
{
    for(int i =1;i<r.size();++i)
    {
        sol = sol + abs(ax-b[i].y);
        sol = sol + abs(r[i]-(r[0]+i));
    }
    return sol;
}

int main()
{
    freopen("BUG.INP","r",stdin);
    freopen("BUG.OUT","w",stdout);
    int n;
    point a[10001];
    cin >> n;
    vector<int> l;
    for(int i=0;i<n;++i)
    {
        cin >> a[i].x >> a[i].y;
        ymx = max(ymx, a[i].y);
        ymn = min(a[i].y, ymn);
        l.push_back(a[i].x);
    }
    int yx = (ymx-ymn)/2;
    int ans = abs(yx-a[0].y);
    sort(l.begin(),l.end());
    cout << fa(ans,a,l,yx);
    return 0;

}
