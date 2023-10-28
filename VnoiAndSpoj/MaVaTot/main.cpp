#include <iostream>
#include <bits/stdc++.h>
#define MaxN 7000
using namespace std;
typedef pair<int, int> pii;
int mx, my, tx, ty, cur, di[8] = {2, 1, -1, -2, -2, -1, 1, 2}, dj[8] = {1, 2, 2, 1, -1, -2, -2, -1}, DX, DY;
bool InQueue[MaxN+1][MaxN+1], vis[MaxN+1][MaxN+1];
const int Base = 3500;
queue<pii> q;

bool Check(int x, int y) {
    return ((x >= -Base) && (x <= Base) && (y >= -Base) && (y <= Base) && (!vis[x + Base][y + Base]) && (abs(x - tx) <= DX) && (abs(y - ty) <= DY));
}

int BFS() {
    q.push(pii(mx, my));
    InQueue[mx+Base][my+Base] = true;
    vis[mx+Base][my+Base] = true;
    int MSteps = 0;
    DX = abs(mx - tx) + 30;
    DY = abs(my - ty) + 30;
    while (true) {
        if (cur == 1) {
            tx--;
            for (int i=0; i<8; i++) {
                int TmpX = tx + di[i] + Base, TmpY = ty + dj[i] + Base;
                if (InQueue[TmpX][TmpY])
                    return MSteps + 1;
            }
        }
        else {
            MSteps++;
            int sz = q.size();
            while (sz > 0) {
                pii u = q.front();
                q.pop();
                sz--;
                int curx = u.first, cury = u.second;
                InQueue[curx + Base][cury + Base] = false;
                for (int i=0; i<8; i++) {
                    int NextX = curx + di[i], NextY = cury + dj[i];
                    if (Check(NextX, NextY)) {
                        q.push(pii(NextX, NextY));
                        InQueue[NextX + Base][NextY + Base] = true;
                        vis[NextX + Base][NextY + Base] = true;
                    }
                }
            }
        }
        cur = 1 - cur;
    }
}

int Solution() {
    if (cur == 1) {
        tx--;
        cur = 1 - cur;
    }
    if ((mx - tx + my - ty)%2 == 0)
        return -1;
    return BFS();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> mx >> my >> tx >> ty >> cur;
    int ans = Solution();
    if (ans == -1)
        cout << "NO";
    else
        cout << "YES\n" << ans;
    return 0;
}
