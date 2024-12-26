#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <int,  null_type,  less,  rb_tree_tag,  tree_order_statistics_node_update > // Thuc chat ordered_set la mot cai CTDL dang cay => nhanh vl =))) co O(logn)
#define ll long long
#define pll pair<long long, long long>
#define pb push_back
#define fi first
#define se second
#define ed '\n'
#define mp make_pair

const ll maxn = 510;
const ll maxx = 1e9;

ll n, m1, m2;
ll x[maxn], y[maxn], u[maxn], v[maxn];
ll dis[maxn][maxn], dis1[maxn][maxn], dis2[maxn][maxn], res;

//
void read_data()
{
    cin >> n;
    cin >> m1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis1[i][j] = maxx;
        }
    }
    for (int i = 1; i <= m1; i++)
    {
        cin >> x[i] >> y[i];
        dis1[x[i]][y[i]] = 1;
        dis1[y[i]][x[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
        dis1[i][i] = 0;

//    for (int k = 1; k <= n; k++)
//    {
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 1; j <= n; j++)
//            {
//                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
//            }
//        }
//    }

    cin >> m2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis2[i][j] = maxx;
        }
    }
    for (int i = 1; i <= m2; i++)
    {
        cin >> u[i] >> v[i];
        dis2[u[i]][v[i]] = 1;
        dis2[v[i]][u[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
        dis2[i][i] = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis1[i][j] = min(dis1[i][j], dis1[i][k] + dis1[k][j]);
                dis2[i][j] = min(dis2[i][j], dis2[i][k] + dis2[k][j]);
                dis[i][j] = max(dis1[i][j], dis2[i][j]);
                dis1[i][j] = dis[i][j];
                dis2[i][j] = dis[i][j];
//                cout << i << " " << j << " " << dis2[i][j] << ed;
//                dis2[j][i] = min(dis2[j][i], dis2[j][k] + dis2[k][i]);
            }
        }
    }
//    cout << ed;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            res += dis[i][j];
        }
    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = i; j <= n; j++)
//        {
//            cout << i << " " << j << " " << dis2[i][j] << ed;
//        }
//    }
    cout << res;
}
//
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    read_data();
    return 0;
}
