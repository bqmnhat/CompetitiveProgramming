#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, gem[2002][2002], LastAns[2001][2001], di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
char a[2001][2001];
bool vis[2001][2001];
stack<pii> stk;

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                gem[i+1][j]++;
                gem[i][j+1]++;
                gem[i-1][j]++;
                gem[i][j-1]++;
            }
        }
    }
}

void DFS(int i, int j) {
    vis[i][j] = true;
    stk.push(pii(i, j));
    LastAns[i][j] += gem[i][j];
    for (int k=0; k<=3; k++) {
        int u = i + di[k], v = j + dj[k];
        if ((u <= n) && (v <= m) && (a[u][v] != '#') && (!vis[u][v])) {
            DFS(u, v);
            LastAns[i][j] += LastAns[u][v];
        }
    }
}

void Solve() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (a[i][j] != '#') {
                if (!vis[i][j])
                    DFS(i, j);
                while (!stk.empty()) {
                    pii tmp = stk.top();
                    LastAns[tmp.first][tmp.second] = LastAns[i][j];
                    stk.pop();
                }
                cout << LastAns[i][j] << ' ';
            }
            else
                cout << "-1 ";
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
