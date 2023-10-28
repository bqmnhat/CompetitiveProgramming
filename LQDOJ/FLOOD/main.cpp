#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
#define MaxK 10000
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
int n, m, k, cost[MaxN+5][MaxN+5], BFSA[MaxN+5][MaxN+5], HPosX, HPosY, GPosX, GPosY, diri[4] = {1, 0, -1, 0}, dirj[4] = {0, 1, 0, -1};
bool vis[MaxN+5][MaxN+5];
vector<pii> SPos;
string a[MaxN+5];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> a[i];
}

void FindHAndG() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 'H') {
                HPosX = i;
                HPosY = j;
            }
            if (a[i][j] == 'G') {
                GPosX = i;
                GPosY = j;
            }
            if (a[i][j] == 'S')
                SPos.push_back(pii(i, j));
        }
    }
}

bool Check(int x, int y) {
    return ((x >= 0) && (y >= 0) && (x < n) && (y < m));
}

bool DijkstraCheck(int k) {
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cost[i][j] = 1e9;
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    cost[HPosX][HPosY] = 0;
    pq.push(piii(cost[HPosX][HPosY], pii(HPosX, HPosY)));
    while (!pq.empty()) {
        pii tmp = pq.top().second;
        int CurCost = pq.top().first;
        pq.pop();
        int ux = tmp.first, uy = tmp.second;
        if (CurCost > cost[ux][uy])
            continue;
        for (int i=0; i<4; i++) {
            int NewUx = ux + diri[i], NewUy = uy + dirj[i];
            if (Check(NewUx, NewUy)) {
                if (cost[ux][uy] + BFSA[NewUx][NewUy] < cost[NewUx][NewUy]) {
                    cost[NewUx][NewUy] = cost[ux][uy] + BFSA[NewUx][NewUy];
                    pq.push(piii(cost[NewUx][NewUy], pii(NewUx, NewUy)));
                }
            }
        }
    }
    return (cost[GPosX][GPosY] <= k);
}

void MakeBFSA(int t) {
    bool vis[MaxN+5][MaxN+5];
    memset(vis, false, sizeof(vis));
    queue<pii> q;
    for (pii x: SPos) {
        vis[x.first][x.second] = true;
        q.push(x);
    }
    int cnt = 1;
    while ((!q.empty()) && (cnt < t)) {
        cnt++;
        int qsize = q.size();
        while (qsize--) {
            int ux = q.front().first, uy = q.front().second;
            q.pop();
            for (int i=0; i<4; i++) {
                int NewUx = ux + diri[i], NewUy = uy + dirj[i];
                if ((Check(NewUx, NewUy)) && (!vis[NewUx][NewUy])) {
                    vis[NewUx][NewUy] = true;
                    BFSA[NewUx][NewUy] = BFSA[ux][uy];
                    q.push(pii(NewUx, NewUy));
                }
            }
        }
    }
    BFSA[HPosX][HPosY] = BFSA[GPosX][GPosY] = 0;
}

bool Check(int t) {
    if (t == 0)
        return true;
    memset(BFSA, 0, sizeof(BFSA));
    for (pii x: SPos)
        BFSA[x.first][x.second] = 1;
    MakeBFSA(t);
    return DijkstraCheck(k);
}

int Solution() {
    int lo = 0, hi = n*m+3, ans = -1;
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        if (Check(mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    if (ans > n*m)
        return -1;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    ReadData();
    FindHAndG();
    cout << Solution();
    return 0;
}
