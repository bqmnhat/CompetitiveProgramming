#include <bits/stdc++.h>
using namespace std;
int yMn= 1e5+10, yMx=-1e5-10;

struct point {
    int x,y;
};

int findAnswer(int sol, point b[10001], vector<int> r, int axis){
    for (int i=1; i<r.size(); ++i)
    {
        sol = sol + abs(axis-b[i].y);
        sol = sol + abs(r[i]-(r[0]+i));
    }
    return sol;
};

int main()
{
    freopen("BUG.INP", "r", stdin);
    freopen("BUG.OUT", "w", stdout);
    int n;
    point a[10001];
    cin >> n;
    vector <int> l;
    for (int i=0; i<n; ++i)
    {
        cin >> a[i].x >> a[i].y;
        yMx= max(yMx, a[i].y);
        yMn= min (a[i].y, yMn);
        l.push_back(a[i].x);
    }
    int yx = (yMx+yMn)/2;
    int ans = abs(yx-a[0].y);
    sort (l.begin(),l.end());
    cout << findAnswer(ans,a,l,yx);
    return 0;
}
