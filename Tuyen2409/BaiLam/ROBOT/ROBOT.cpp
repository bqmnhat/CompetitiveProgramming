#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
typedef pair<int, int> pii;
int n, m, k, diri[4] = {-1, 0, 1, 0}, dirj[4] = {0, 1, 0, -1}, PreDir;
int check[MaxN+1][MaxN+1][10][5], vis[MaxN+1][MaxN+1][10][5];
string s[MaxN+1], cmd;

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> s[i];
    cin >> cmd;
}

void Init() {
    for (int i=0; i<MaxN; i++)
        for (int j=0; j<MaxN; j++)
            for (int t=0; t<10; t++)
                for (int l=0; l<5; l++)
                    vis[i][j][t][l] = 0;
}

bool Check(int x, int y) {
    return ((x >= 0) && (x < n) && (y >= 0) && (y < m) && (s[x][y] != '#'));
}

bool DFS(int i, int j, int CurCmd, int dir) {
    if (vis[i][j][CurCmd][dir] == 1) {
        vis[i][j][CurCmd][dir] = 2;
        return (check[i][j][CurCmd][dir] = false);
    }
    vis[i][j][CurCmd][dir] = 1;
    if (s[i][j] == 'E') {
        vis[i][j][CurCmd][dir] = 2;
        return (check[i][j][CurCmd][dir] = true);
    }
    if (vis[i][j][CurCmd][dir] == 2)
        return (check[i][j][CurCmd][dir]);
    int NxtI = i, NxtJ = j, NxtDir = dir;
    if (cmd[CurCmd] == 'F') {
        NxtI += diri[dir];
        NxtJ += dirj[dir];
        if (!Check(NxtI, NxtJ)) {
            NxtI = i;
            NxtJ = j;
        }
    }
    else if (cmd[CurCmd] == 'L')
        NxtDir = (dir + 3)%4;
    else
        NxtDir = (dir + 1)%4;
    check[i][j][CurCmd][dir] = DFS(NxtI, NxtJ, (CurCmd + 1)%k, NxtDir);
    vis[i][j][CurCmd][dir] = 2;
    return (check[i][j][CurCmd][dir]);
}

void Solve() {
    int ans = 0, cnt = 0;
    //vector<pii> Points; // debug part
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (s[i][j] == '#') {
                vis[i][j][0][0] = 2;
                check[i][j][0][0] = false;
                continue;
            }
            cnt++;
            if (vis[i][j][0][0] == 0) {
                if (DFS(i, j, 0, 0)) {
                    ans++;
                    //Points.push_back(pii(i, j)); // Debug part
                }
            }
            else if ((vis[i][j][0][0] == 2) && (check[i][j][0][0])) {
                ans++;
                //Points.push_back(pii(i, j)); // debug part
            }
        }
    }
    if (ans == cnt)
        cout << "YES";
    else
        cout << ans;
    // Debug part
    /*cout << '\n';
    for (pii x: Points)
        cout << x.first << ' ' << x.second << '\n';*/
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    cin >> n >> m >> k;
    ReadData();
    Init();
    Solve();
    return 0;
}

