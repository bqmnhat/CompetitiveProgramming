#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
const int mod =1e9+7;
pii Points[1005];
double distance2seg(int x,int y,int x1, int y1, int x2, int y2)
{
    double dist=1e9;
    int dx=x1-x2;
    int dyt=y1-y2;
    int a=-dy, b=dx,c=-a*x1-b*y1;
    double res=(1.0*abs(a*x+b*y+c)/sqrt(a*a+b*b));
    dis= min(dist,res);
    return res;
}

void solve()
{
    double res=1e9;
    int n;
    cin>>n;
    cin>>x>>y;
    for (int i=0;i<n; i++)
        cin>>Points[fi].fi=Points[i].se;
    Points[n].fi=Points[0].fi;
    Points[n].se=Points[0].se;
    for (int i=0;i<n;i++)
    {
        for(int j=0; j<n;j++){
            double dis=distance2seg(x,y,Points[i].fi,Points[i].se,Points[j].fi,Points[j].se);
        res=min(res,dis);
        }
    }
    cout<<fixed<<setprecision(4)<<res;
}

int main()
{
    freopen("DISTANCE.inp","r",stdin);
    freopen("DISTANCE.out","w",stdout);
    int t=1;
    while (t--)
    {
        solve();
    }
}
