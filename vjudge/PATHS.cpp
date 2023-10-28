#include <bits/stdc++.h>
#define fo(i,m,n) for(int i = m; i <= n; i++)
#define fod(i,m,n) for(int i = m; i >= n; i--)
#define fov(i,x) for(auto &i : x)
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
const int N = 2e5+7;
struct Edge
{
	int u,v;
	i64 d;
};
int n,m,dsu[N];
i64 tree_length,maxx[N][20];
int d[N],step[N][20];
set <_ii> A;
vector <Edge> edge,edge_data;
vector <_ii> a[N];
int Find(int x)
{
	int y = x;
	while(dsu[y] != y) y = dsu[y];
	dsu[x] = y;
	return y;
}
void DFS(int h, int legacy)
{
	d[h] = d[legacy]+1;
	fov(i,a[h])
	{
		if(i.first == legacy) continue;
		d[i.first] = d[h]+1;
		step[i.first][0] = h;
		maxx[i.first][0] = i.second;
		DFS(i.first,h);
	}
}
void LCA_pre()
{
	fo(u,1,19)
	{
		fo(i,1,n)
		{
			int v = step[i][u-1];
			step[i][u] = step[v][u-1];
			maxx[i][u] = max(maxx[i][u-1],maxx[v][u-1]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	fo(i,1,m)
	{
		int x,y,z;
		cin >> x >> y >> z;
		edge.push_back({x,y,z});
		edge_data.push_back({x,y,z});
	}
	sort(edge.begin(),edge.end(),[](Edge &a, Edge &b)
	{
		return a.d < b.d;
	});
	fo(i,1,n) dsu[i] = i;
	fov(i,edge)
	{
		int u = Find(i.u);
		int v = Find(i.v);
		if(u == v) continue;
		//cout << ' ' << i.u << ' ' << i.v << ' ' << i.d << '\n';
		tree_length += i.d;
		A.insert({min(i.u,i.v),max(i.u,i.v)});
		a[i.u].push_back({i.v,i.d});
		a[i.v].push_back({i.u,i.d});
		if(u < v) dsu[v] = u;
		else dsu[u] = v;
	}
	DFS(1,0);
	LCA_pre();
	fov(i,edge_data)
	{
		i64 ans = tree_length;
		if(i.u > i.v) swap(i.u,i.v);
		if(A.find({i.u,i.v}) == A.end())
		{
			i64 delete_length = 0;
			int x = i.u;
			int y = i.v;
			if(d[x] > d[y]) swap(x,y);
			int delta = d[y]-d[x];
			int temp = 0;
			while(delta)
			{
				if(delta&1)
				{
					delete_length = max(delete_length,maxx[y][temp]);
					y = step[y][temp];
				}
				++temp;
				delta >>= 1;
			}
			if(x != y)
			{
				while(step[x][0] != step[y][0])
				{
					int L = 0, R = 19;
					while(L < R)
					{
						int mid = (L+R+1) >> 1;
						if(step[x][mid] == step[y][mid]) R = mid-1;
						else L = mid;
					}
					delete_length = max(delete_length,maxx[x][L]);
					delete_length = max(delete_length,maxx[y][L]);
					x = step[x][L];
					y = step[y][L];
				}
				delete_length = max(delete_length,maxx[x][0]);
				delete_length = max(delete_length,maxx[y][0]);
			}
			ans = ans - delete_length + i.d;
		}
		cout << ans << '\n';
	}
}