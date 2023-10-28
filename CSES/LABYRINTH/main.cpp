#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x, y;
}trace[1001][1001];
int n,m,xA,yA,xB,yB, a[5] = {0,-1,0,1,0}, b[5] = {0,0,1,0,-1};
string s[1001];
char dir[5] = {' ', 'D', 'L', 'U', 'R'}, sans[1000001];
queue<Point> q;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
}

bool check(int x, int y) {
    return ((x<=n) && (x>=1) && (y<=m) && (y>=1));
}

void FindXY() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (s[i][j] == 'A') {
                xA = i;
                yA = j;
            }
            if (s[i][j] == 'B') {
                xB = i;
                yB = j;
            }
        }
    }
}

void PrintAns() {
    if ((trace[xB][yB].x == 0) && (trace[xB][yB].y == 0)) {
        cout << "NO";
        return;
    }
    cout << "YES" << '\n';
    int xx = xB, yy = yB, ans = 0;
    while (trace[xx][yy].x != -1) {
        for (int i=1; i<=4; i++) {
            if ((trace[xx][yy].x == xx + a[i]) && (trace[xx][yy].y == yy + b[i])) {
                ans++;
                sans[ans] = dir[i];
                break;
            }
        }
        int tmp = xx;
        xx = trace[xx][yy].x;
        yy = trace[tmp][yy].y;
    }
    cout << ans << '\n';
    for (int i=ans; i>=1; i--) {
        cout << sans[i];
    }
}

void MinRoute() {
    Point t;
    t.x = xA;
    t.y = yA;
    q.push(t);
    trace[xA][yA].x = trace[xA][yA].y = -1;
    while (true) {
        Point u = q.front();
        q.pop();
        for (int i=1; i<=4; i++) {
            int x1 = u.x + a[i], y1 = u.y + b[i];
            if ((check(x1,y1)) && (trace[x1][y1].x == 0) && (trace[x1][y1].y == 0) && (s[x1][y1] != '#')) {
                trace[x1][y1].x = u.x;
                trace[x1][y1].y = u.y;
                Point New;
                New.x = x1;
                New.y = y1;
                q.push(New);
            }
        }
        if (q.empty())
            break;
    }
    PrintAns();
}

int main()
{
    cin >> n >> m;
    ReadData();
    FindXY();
    MinRoute();
    return 0;
}
