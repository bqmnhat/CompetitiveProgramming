#include<bits/stdc++.h>
using namespace std;

#define ed '\n'
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>

int n,m;
char a[1001][1001], res[1000005];
pii Start, End;
int vis[1001][1001];

int  row[5] = { 0 , -1 , 0 , 0 , 1 };
int  col[5] = { 0 ,  0 ,-1 , 1 , 0 };
char des[5] = {'M', 'U','L','R','D'};

//
void bfs()
{
    queue<pii> q;
    q.push(Start);
    while (!q.empty())
    {
        pii par = q.front();
        q.pop();
        for (int i = 1; i <= 4; i++)
        {
            int u = par.fi + row[i];
            int v = par.se + col[i];
            if (u < 1 || u > n || v < 1 || v > m) continue;
            if (a[u][v] == '.' && vis[u][v] == 0)
            {
                q.push(mp(u,v));
                vis[u][v] = i;
            }
            else if (a[u][v] == 'B')
            {
                vis[u][v] = i;
                return;
            }
        }
    }

}
//
void sol()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                Start = mp(i,j);
            }
            else if (a[i][j] == 'B')
            {
                End = mp(i,j);
            }
        }
    }

    bfs();
    if (vis[End.fi][End.se] == 0)
    {
        cout << "NO";
        return;
    }
    cout << "YES" << ed;
    pii id = End;
    int cnt = 0;
    while (id != Start)
    {
        int i = vis[id.fi][id.se];
        cnt++;
        res[cnt] = des[i];
        id.fi -= row[i];
        id.se -= col[i];
    }
    cout << cnt << ed;
    for (int i=cnt; i>=1; i--)
        cout << res[i];
}
//
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sol();
    return 0;
}
