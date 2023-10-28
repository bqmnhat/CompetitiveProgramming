#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> Ipair;
int n, m, g[101][101], di[5] = {0, -1, 0, 1, 0}, dj[5] = {0, 0, 1, 0, -1};
bool visited[101][101];
Ipair VertexSt;

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 2) {
                VertexSt.first = i;
                VertexSt.second = j;
            }
        }
    }
}

bool Check(int u, int v) {
    return ((u >= 1) && (u <= n) && (v >= 1) && (v <= m));
}

int BFS(int i, int j) {
    int ans = 1e9 - 1;
    if ((i == 1) || (j == 1) || (i == n) || (j == m))
        return 0;
    for (int t=1; t<=4; t++) {
        int u = i+di[t], v = j+dj[t];
        if ((Check(u,v)) && (!visited[u][v]) && (g[u][v] == 0)) {
            visited[u][v] = true;
            ans = min(ans, BFS(u,v));
        }
    }
    return ans+1;
}

int main()
{
    cin >> n >> m;
    ReadData();
    int tmp = BFS(VertexSt.first, VertexSt.second);
    if (tmp == 1e9) {
        cout << -1;
    }
    else
        cout << tmp;
    return 0;
}
