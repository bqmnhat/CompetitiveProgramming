#include <bits/stdc++.h>

using namespace std;
#define FAST		    ios_base::sync_with_stdio(false); cin.tie(NULL);
#define prs(n)		    cout << fixed << setprecision(n)
#define ll			    long long
#define db			    double
#define fo(i,m,n)       for(int i = m; i <= n; i++)
#define fob(i,m,n)      for(int i = n; i >= m; i--)
typedef                 pair<int, int> ii;
typedef                 vector<ii> vii;
typedef                 vector<vii> vvii;
const                   int maxi=INT_MAX;
const                   int _x[] = {-1,-1,-1,0,0,1,1,1};
const                   int _y[] = {-1,0,1,-1,1,-1,0,1};

const int mod=1e9+7, N=2e5+7;

struct edge
{
   int u, v, d;
} ;

struct Dsu
{
    vector <int> parent;
    void init(int n)
    {
        parent.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int findset(int a)
    {
        return a == parent[a] ? a : findset(parent[a]);
    }

    bool joint(int a, int b)
    {
        a = findset(a);
        b = findset(b);
        if (a == b) return false;
        parent[b] = a;
        return true;
    }
}dsu;

bool cmp(edge a, edge b)
{
    return a.d < b.d;
}

int n, m, a[N], x, y, w;
vector <edge> gra;

void input()
{
    cin >> n >> m;
    fo(i,0,n-1) cin >> a[i];
    fo(i,1,n-1)
    {
        fo(j,0,i-1)
        {
            gra.push_back({i,j,a[i] + a[j]});
        }
    }
    while(m--)
    {
        cin >> x >> y >> w;
        if (a[x] + a[y] > w)
        {
            gra.push_back({x,y,w});
        }
    }
}

void solve()
{
    stack <ii> s;
    int ans = 0;
    dsu.init(n);
    sort(gra.begin(), gra.end(), cmp);
    for (auto i:gra)
    {
        if (!dsu.joint(i.u, i.v)) continue;
        ans += i.d;
        s.push({i.u,i.v});
    }
    cout << ans;
}

int main()
{
    FAST
    freopen("MKC.INP", "r", stdin);
    freopen("MKC.OUT", "w", stdout);
    int t;
        input();
        solve();
    return 0;
}
