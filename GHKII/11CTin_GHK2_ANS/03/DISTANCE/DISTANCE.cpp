#include <bits/stdc++.h>

using namespace std;
pair<int,int>a[1001];
int u,v;
double res[1001];
double kc(int x)
{
    return sqrt(pow(a[x].first-u,2)+pow(a[x].second-v,2));
}
int main()
{
    freopen("DISTANCE.INP","r",stdin);
    freopen("DISTANCE.OUT","w",stdout);

    int n;
    cin>>n>>u>>v;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
        res[i]=kc(i);
    }
    sort(res+1,res+n+1);
    cout<<fixed<<setprecision(4)<<sqrt(1/(1/pow(res[1],2)+1/pow(res[2],2)));

}
