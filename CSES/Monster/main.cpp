#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
int n, m, MDist[MaxN+5][MaxN+5], xA, yA, trace[MaxN+5][MaxN+5];
int diri[4] = {0, -1, 0, 1}, dirj[4] = {-1, 0, 1, 0};
char DirChar[4] = {'L', 'U', 'R', 'D'};
vector<pii> MPoint;
bool vis[MaxN+5][MaxN+5];
string s[MaxN+5];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> s[i];
}

void Init() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            MDist[i][j] = INF;
            if (s[i][j] == 'A') {
                xA = i;
                yA = j;
            }
            else if (s[i][j] == 'M')
                MPoint.push_back(pii(i, j));
        }
    }
}

bool Check(int x, int y) {
    return ((x >= 0) && (x < n) && (y >= 0) && (y < m));
}

void FirstBFS(const vector<pii>& srcs) {
    queue<pii> q;
    for (pii tmp: srcs) {
        MDist[tmp.first][tmp.second] = 0;
        q.push(tmp);
    }
    int cnt = 0;
    while (!q.empty()) {
        int qsize = q.size();
        cnt++;
        while (qsize) {
            pii tmp = q.front();
            q.pop();
            qsize--;
            int x = tmp.first, y = tmp.second;
            for (int i=0; i<4; i++) {
                int NewX = x + diri[i], NewY = y + dirj[i];
                if ((Check(NewX, NewY)) && (!vis[NewX][NewY]) && (s[NewX][NewY] != '#')) {
                    vis[NewX][NewY] = true;
                    MDist[NewX][NewY] = min(MDist[NewX][NewY], cnt);
                    q.push(pii(NewX, NewY));
                }
            }
        }
    }
}

bool CheckOnEdge(int x, int y) {
    return ((x == 0) || (y == 0) || (x == n-1) || (y == m-1));
}

int SecondBFS(pii src, pii& ex) {
    queue<pii> q;
    q.push(src);
    memset(vis, false, sizeof(vis));
    int cnt = 0;
    while (!q.empty()) {
        int qsize = q.size();
        cnt++;
        while (qsize) {
            pii tmp = q.front();
            q.pop();
            qsize--;
            int x = tmp.first, y = tmp.second;
            if (CheckOnEdge(x, y)) {
                ex = pii(x, y);
                return (cnt-1);
            }
            for (int i=0; i<4; i++) {
                int NewX = x + diri[i], NewY = y + dirj[i];
                if ((Check(NewX, NewY)) && (!vis[NewX][NewY]) && (s[NewX][NewY] != '#') && (cnt < MDist[NewX][NewY])) {
                    vis[NewX][NewY] = true;
                    trace[NewX][NewY] = i;
                    q.push(pii(NewX, NewY));
                }
            }
        }
    }
    return -1;
}

void Solve() {
    Init();
    FirstBFS(MPoint);
    pii ex;
    int ans = SecondBFS(pii(xA, yA), ex);
    if (ans != -1)
        cout << "YES\n" << ans << '\n';
    else {
        cout << "NO";
        return;
    }
    int x = ex.first, y = ex.second;
    vector<char> DirAns;
    DirAns.clear();
    while ((x != xA) || (y != yA)) {
        DirAns.push_back(DirChar[trace[x][y]]);
        int oldx = x, oldy = y;
        x = oldx - diri[trace[oldx][oldy]];
        y = oldy - dirj[trace[oldx][oldy]];
    }
    reverse(DirAns.begin(), DirAns.end());
    for (int i=0; i<DirAns.size(); i++)
        cout << DirAns[i];
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
