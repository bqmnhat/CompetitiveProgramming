#include <iostream>
#include <bits/stdc++.h>
#define MaxN 20
#define MaxD 205
#define Base 200
using namespace std;
typedef pair<int, int> pii;
int x, y, n, d, dp[MaxD+Base][MaxD+Base]; // Don't need to use the reflection because if we reflect a point => NxtX = y and NxtY = x...BUT the criteria for Cheking if the point is out of distance d from the Decartes' plain origin is (x*x) + (y*y) = (y*y) + (x*x) <= d
vector<pii> Moves;

void ReadData() {
    for (int i=1; i<=n; i++) {
        int dx, dy;
        cin >> dx >> dy;
        Moves.push_back(pii(dx, dy));
    }
}

bool CheckDist(int x, int y, int d) {
    x -= Base;
    y -= Base;
    return (x*x + y*y <= d*d);
}

int CalDp(int x, int y) {
    if (!CheckDist(x, y, d))
        return dp[x][y] = 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    for (pii mv: Moves) {
        int dx = mv.first, dy = mv.second;
        int NxtX = x + dx, NxtY = y + dy;
        if (!(CheckDist(NxtX, NxtY, d)))
            continue;
        if (CalDp(NxtX, NxtY) == 0)
            return dp[x][y] = 1;
    }
    return dp[x][y] = 0;
}

void Solve() {
    memset(dp, -1, sizeof(dp));
    int ans = CalDp(x + Base, y + Base);
    if (ans == 1)
        cout << "Anton";
    else
        cout << "Dasha";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> y >> n >> d;
    ReadData();
    Solve();
    return 0;
}
