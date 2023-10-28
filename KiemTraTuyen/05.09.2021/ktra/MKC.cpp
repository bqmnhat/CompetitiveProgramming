#include <bits/stdc++.h>

using namespace std;
struct edge
{
    int x,y,d;
};

int n,m,ans=0;
vector <edge> graph;
vector <int> dsu;
vector <int> a;

int find(int a)
{
    while(dsu[a]!=a) a=dsu[a];
    return a;
}

int cmp(edge a, edge b)
{
    return a.d < b.d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    freopen("MKC.INP", "r", stdin);
    freopen("MKC.OUT", "w", stdout);

    cin >> n >> m;
    a.resize(n+1);
    bool check[n+1][n+];

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    if(m==0)
    {
        sort(a.begin(),a.end());
        ans=a[0]*(n-1);
        for(int i=1;i<n;i++)
            ans+=a[i];
        cout << ans;
    }
    else
    {
        graph.resize(n+1);
        dsu.resize(n+1);
        for(int i=0; i<n; i++) dsu[i]=i;
        for(int i=0; i<m; i++)
        {
            int x,y,w;
            cin >> x >> y >> w;
            if(w<a[x]+a[y])
            {
                graph.push_back({x,y,w});
                check[x][y]=true;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                check[i][j]=false;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {
                    if(check[i][j]==false)
                    {
                        graph.push_back({i,j,(a[i]+a[j])});
                    }
                }
        }
        sort(graph.begin(),graph.end(),cmp);
        for(auto i : graph)
        {
            int u=find(i.x);
            int v=find(i.y);
            if(u==v) continue;
            ans += i.d;
            if(u<v) dsu[v]=u;
            else dsu[u]=v;
        }
        cout << ans;
    }
}
