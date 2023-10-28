#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,p,q,s,t, di[4] = {-1, -1, 1, 1}, dj[4] = {-1, 1, 1, -1};
bool table[201][201], visited[201][201];

struct pos {
    int u,v,dist;
};

void ReadData() {
    int r,c;
    for (int i=1; i<=m; i++) {
        cin >> r >> c;
        table[r][c] = true;
    }
}

bool Check(int NewU, int NewV) {
    return ((NewU >= 1) && (NewV >= 1) && (NewU <= n) && (NewV <= n) && (!table[NewU][NewV]));
}

void BFS(int p, int q, int s, int t) {
    queue<pos> qu;
    qu.push({p,q,0});
    while (!qu.empty()) {
        pos CurBox = qu.front();
        qu.pop();
        visited[CurBox.u][CurBox.v] = true;
        for (int i=0; i<=3; i++) {
            int NewU = CurBox.u, NewV = CurBox.v, NewDist = CurBox.dist + 1;
            NewU += di[i];
            NewV += dj[i];
            while (Check(NewU, NewV)) {
                if (!visited[NewU][NewV]) {
                    qu.push({NewU, NewV, NewDist});
                    if ((NewU == s) && (NewV == t)) {
                        cout << NewDist;
                        return;
                    }
                }
                NewU += di[i];
                NewV += dj[i];
            }
        }
    }
    cout << "-1";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> p >> q >> s >> t;
    ReadData();
    BFS(p,q,s,t);
    return 0;
}
