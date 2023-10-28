#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
using namespace std;
typedef long long ll;
struct Dice {
    ll Top, Down, Left, Right, Front, Back;
};
struct ForPq {
    ll c;
    Dice d;
    int x, y;
    bool operator < (const ForPq& o) const {
        return (c > o.c);
    }
};
const ll INF = 1e9 + 7;
int m, n, x1, Y1, x2, y2;
int diri[4] = {0, -1, 0, 1}, dirj[4] = {-1, 0, 1, 0};
ll Cost[MaxN+5][MaxN+5][8][8], a[MaxN+5][MaxN+5];

void ReadData() {
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
    cin >> x1 >> Y1 >> x2 >> y2;
}

bool Check(int x, int y) {
    return ((x >= 1) && (x <= m) && (y >= 1) && (y <= n));
}

void Init() {
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            for (int k=0; k<=7; k++)
                for (int t=0; t<=7; t++)
                    Cost[i][j][k][t] = INF;
}

Dice Left(Dice x) {
    Dice res = x;
    res.Top = x.Right;
    res.Down = 7 - res.Top;
    res.Left = x.Top;
    res.Right = 7 - res.Left;
    return res;
}

Dice Right(Dice x) {
    Dice res = x;
    res.Top = x.Left;
    res.Down = 7 - res.Top;
    res.Right = x.Top;
    res.Left = 7 - res.Right;
    return res;
}

Dice Backward(Dice x) {
    Dice res = x;
    res.Top = x.Back;
    res.Down = 7 - res.Top;
    res.Front = x.Top;
    res.Back = 7 - res.Front;
    return res;
}

Dice Forward(Dice x) {
    Dice res = x;
    res.Top = x.Front;
    res.Down = 7 - res.Top;
    res.Back = x.Top;
    res.Front = 7 - res.Back;
    return res;
}

void Dijkstra(int sx, int sy) {
    priority_queue<ForPq> pq;
    Cost[sx][sy][5][1] = 5*a[sx][sy];
    pq.push({Cost[sx][sy][5][1], {2, 5, 4, 3, 1, 6}, sx, sy});
    while (!pq.empty()) {
        ForPq tmp = pq.top();
        pq.pop();
        ll c = tmp.c;
        Dice d = tmp.d;
        int x = tmp.x, y = tmp.y;
        if (c > Cost[x][y][d.Down][d.Front]) continue;
        for (int i=0; i<4; i++) {
            int NewX = x + diri[i], NewY = y + dirj[i];
            Dice NewD;
            if (i == 0)
                NewD = Left(d);
            if (i == 1)
                NewD = Forward(d);
            if (i == 2)
                NewD = Right(d);
            if (i == 3)
                NewD = Backward(d);
            if ((Check(NewX, NewY)) && (Cost[NewX][NewY][NewD.Down][NewD.Front] > Cost[x][y][d.Down][d.Front] + NewD.Down*a[NewX][NewY])) {
                Cost[NewX][NewY][NewD.Down][NewD.Front] = Cost[x][y][d.Down][d.Front] + NewD.Down*a[NewX][NewY];
                pq.push({Cost[NewX][NewY][NewD.Down][NewD.Front], NewD, NewX, NewY});
            }
        }
    }
}

ll Solution() {
    Init();
    Dijkstra(x1, Y1);
    ll ans = INF;
    for (int i=1; i<=6; i++) {
        for (int j=1; j<=6; j++) {
            if ((i == j) || (j == 7 - i))
                continue;
            ans = min(ans, Cost[x2][y2][i][j]);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    ReadData();
    cout << Solution();
    return 0;
}
