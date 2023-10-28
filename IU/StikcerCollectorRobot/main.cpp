#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
int n, m, S, iniI, iniJ, IniFacing, diri[4] = {-1, 0, 1, 0}, dirj[4] = {0, 1, 0, -1};
bool vis[MaxN+1][MaxN+1];
string cmd, s[MaxN+1];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> s[i];
}

void FindInit() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if ((s[i][j] != '.') && (s[i][j] != '#') && (s[i][j] != '*')) {
                iniI = i;
                iniJ = j;
                if (s[i][j] == 'N')
                    IniFacing = 0;
                else if (s[i][j] == 'S')
                    IniFacing = 2;
                else if (s[i][j] == 'L')
                    IniFacing = 1;
                else
                    IniFacing = 3;
            }
        }
    }
}

bool Check(int x, int y) {
    return ((x >= 0) && (x < n) && (y >= 0) && (y < m) && (s[x][y] != '#'));
}

int TestCaseSolution() {
    memset(vis, false, sizeof(vis));
    int curFacing = IniFacing, CurI = iniI, CurJ = iniJ, ans = 0;
    for (int i=0; i<S; i++) {
        if ((cmd[i] == 'F') && (Check(CurI + diri[curFacing], CurJ + dirj[curFacing]))) {
            CurI += diri[curFacing];
            CurJ += dirj[curFacing];
            if ((s[CurI][CurJ] == '*') && (!vis[CurI][CurJ])) {
                ans++;
                vis[CurI][CurJ] = true;
            }
        }
        if (cmd[i] == 'D')
            curFacing = (curFacing + 1)%4;
        if (cmd[i] == 'E')
            curFacing = (curFacing + 3)%4;
    }
    return ans;
}

void Solve() {
    while ((cin >> n >> m >> S) && ((n != 0) || (m != 0) || (S != 0))) {
        ReadData();
        cin >> cmd;
        FindInit();
        cout << TestCaseSolution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
