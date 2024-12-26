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

const ll maxn = 110;

ll n, m, a[maxn][maxn];
vector<pll> Edit;
ll C[maxn], R[maxn], Col[maxn], Row[maxn];
ll sua[maxn];
bool ok = false;
//

//
void Check()
{
    for (int i = 0; i < Edit.size(); i++)
    {
        a[Edit[i].fi][Edit[i].se] = sua[i];
    }
    for (int i = 1; i <= n; i++)
        Row[i] = 0;
    for (int j = 1; j <= m; j++)
        Col[j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            Col[j] += a[i][j];
            Row[i] += a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
        if (Row[i] != R[i]) return;
    for (int j = 1; j <= m; j++)
        if (Col[j] != C[j]) return;
    ok = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << ed;
    }
}
//
void dq(int id)
{
    if (ok) return;
    if (id == Edit.size())
    {
        Check(); return;
    }
    sua[id] = 0;
    dq(id+1);
    sua[id] = 1;
    dq(id+1);
}
//
void read_data()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
//            if (a[i][j] != -1)
//            {
//                Col[j] += a[i][j];
//                Row[i] += a[i][j];
//            }
            if (a[i][j] == -1)
            {
                Edit.pb(mp(i,j));
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cin >> R[i];
    for (int j = 1; j <= m; j++)
        cin >> C[j];
    dq(0);
}
//
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    read_data();
    return 0;
}
