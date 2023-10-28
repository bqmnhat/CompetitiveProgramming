#include <bits/stdc++.h>
using namespace std;

struct diem
{
    int x, y;
};
int Solve(int s, diem b[10001], vector<int> t, int a)
{
    for(int i=1; i<t.size(); i++)
    {
        s+=abs(a-b[i].y);
        s+=abs(t[i]-(t[0]+i));
    }
    return s;
}
int main()
{
    freopen("BUG.INP", "r", stdin);
    freopen("BUG.OUT", "w", stdout);
    int n, Min=1e5+10, Max=-1e5-10;
    diem a[10001];
    cin>>n;
    vector<int> l;
    for(int i=0; i<n; i++)
    {
        cin>>a[i].x>>a[i].y;
        Max= max(Max, a[i].y);
        Min = min(Min, a[i].y);
        l.push_back(a[i].x);
    }
    int temp=(Max+Min)/2;
    int ans=abs(temp-a[0].y);
    sort(l.begin(), l.end());
    cout<<Solve(ans, a, l, temp);
    return 0;
}
