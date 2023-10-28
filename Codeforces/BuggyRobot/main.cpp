#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
using namespace std;
struct Status {
    int x, y, k;
};
typedef pair<int, int> pii;
int n, m, dp[MaxN][MaxN][MaxN], l, diri[5] = {0, -1, 0, 1, 0}, dirj[5] = {0, 0, 1, 0, -1}, CharDir[257];
string s[MaxN], cmd;
queue<Status> q;
pii StPos, FiPos;

void Init() {
    CharDir['U'] = 1;
    CharDir['R'] = 2;
    CharDir['D'] = 3;
    CharDir['L'] = 4;
    for (int i=0; i<MaxN; i++)
        for (int j=0; j<MaxN; j++)
            for (int k=0; k<MaxN; k++)
                dp[i][j][k] = 1e9;
}

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> s[i];
    cin >> cmd;
    cmd = ' ' + cmd;
}

void FindStAndFi() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (s[i][j] == 'R')
                StPos = pii(i, j);
            if (s[i][j] == 'E')
                FiPos = pii(i, j);
        }
    }
}

bool Check(int x, int y) {
    return ((x >= 0) && (y >= 0) && (x < n) && (y < m) && (s[x][y] != '#'));
}

void BFS(Status src) {
    q.push(src);
    dp[src.x][src.y][src.k] = 0;
    while (!q.empty()) {
        Status u = q.front();
        q.pop();
        int x = u.x, y = u.y, pos = u.k;
        for (int i=1; i<=4; i++) {
            int NxtX = x + diri[i], NxtY = y + dirj[i];
            if ((Check(NxtX, NxtY)) && (dp[NxtX][NxtY][pos] > dp[x][y][pos] + 1)) {
                dp[NxtX][NxtY][pos] = dp[x][y][pos] + 1;
                q.push({NxtX, NxtY, pos});
            }
        }
        if (pos < l) {
            if ((Check(x, y)) && (dp[x][y][pos] + 1 < dp[x][y][pos+1])) {
                dp[x][y][pos+1] = dp[x][y][pos] + 1;
                q.push({x, y, pos+1});
            }
            int NxtX = x + diri[CharDir[cmd[pos+1]]], NxtY = y + dirj[CharDir[cmd[pos+1]]];
            if (!Check(NxtX, NxtY)) {
                NxtX = x;
                NxtY = y;
            }
            if (dp[NxtX][NxtY][pos+1] > dp[x][y][pos]) {
                dp[NxtX][NxtY][pos+1] = dp[x][y][pos];
                q.push({NxtX, NxtY, pos+1});
            }
        }
    }
}

int Solution() {
    Init();
    l = cmd.length()-1;
    FindStAndFi();
    BFS({StPos.first, StPos.second, 0});
    int ans = 1e9;
    for (int i = 1; i<=l; i++)
        ans = min(ans, dp[FiPos.first][FiPos.second][i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
