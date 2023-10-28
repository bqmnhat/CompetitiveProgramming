#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Ipair;
int n, m, trace2[51][51], Q, sx, sy, fx, fy, di[5] = {0, 1, 0, 0, -1}, dj[5] = {0, 0, -1, 1, 0};
char Dir[5] = {' ', 'D', 'L', 'R','U'};
string s[51];
queue <Ipair> q;
Ipair trace1[51][51];

void Init() {
    while (!q.empty())
        q.pop();
    for (int i=1; i<=50; i++) {
        for (int j=1; j<=50; j++) {
            trace1[i][j] = make_pair(0,0);
            trace2[i][j] = 0;
        }
    }
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
}

void PrintAns() {
    string ans = "";
    int i = trace2[fx][fy], x = fx, y = fy;
    while (i != -1) {
        ans = ans + Dir[i];
        int tmp = trace1[x][y].second;
        x = trace1[x][y].first;
        y = tmp;
        i = trace2[x][y];
    }
    int l = ans.length()-1;
    for (int i = l; i>=0; i--)
        cout << ans[i];
}

bool Check(int x, int y) {
    return ((x >= 1) && (x <= n) && (y >= 1) && (y <= m));
}

void BFS(int x, int y) {
    trace2[x][y] = -1;
    trace1[x][y] = make_pair(0,0);
    q.push(make_pair(x,y));
    while (!q.empty()) {
        Ipair p = q.front();
        q.pop();
        int xx = p.first, yy = p.second;
        if ((xx == fx) && (yy == fy)) {
            PrintAns();
            return;
        }
        for (int t = 1; t <= 4; t++) {
            int NewX = xx+di[t], NewY = yy+dj[t];
            if ((Check(NewX, NewY)) && (trace2[NewX][NewY] == 0) && (s[NewX][NewY] != '#')) {
                trace2[NewX][NewY] = t;
                trace1[NewX][NewY] = make_pair(xx,yy);
                q.push(make_pair(NewX, NewY));
            }
        }
    }
    cout << "Impossible";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cin >> Q;
    for (int i=1; i<=Q; i++) {
        cin >> sx >> sy >> fx >> fy;
        BFS(sx,sy);
        cout << '\n';
        Init();
    }
    return 0;
}
