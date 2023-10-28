#include <iostream>
#include <bits/stdc++.h>
#define MaxN 102
using namespace std;
int r, n, dx[3] = {-1, 0, 1}, dp[MaxN+1][3][3];
bool vis[MaxN+1][5];

void Reclaim(int ri, int ci) { // O(5)
    vis[ri][ci] = true;
    for (int j = 0; j<3; j++) {
        int NxtR = ri + dx[j], NxtC = 3 - ci;
        vis[NxtR][NxtC] = true;
    }
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        int ri, ci;
        cin >> ri >> ci;
        Reclaim(ri, ci);
    }
}

int Grundy(int l, int StBlock, int EdBlock) {
    if (l == 0)
        return 0;
    if (dp[l][StBlock][EdBlock] != -1)
        return dp[l][StBlock][EdBlock];
    unordered_set<int> mex;
    for (int i=1; i<=l; i++) {
        for (int j=1; j<=2; j++) {
            if ((i == 1) && (j == StBlock))
                continue;
            if ((i == l) && (j == EdBlock))
                continue;
            mex.insert(Grundy(i-1, StBlock, 3-j)^Grundy(l-i, 3-j, EdBlock));
        }
    }
    int g = 0;
    while (mex.count(g))
        g++;
    return dp[l][StBlock][EdBlock] = g;
}

void Solve() {
    memset(dp, -1, sizeof(dp));
    int st = 0, ed = 0, len = 0, win = 0;
    for (int i=1; i<=r; i++) {
        int RowState = 1, BlockedCol = 0;
        for (int j=1; j<=2; j++) {
            if (vis[i][j] == true) {
                RowState--;
                BlockedCol = j;
            }
        }
        if (RowState == -1) {
            win ^= Grundy(len, st, ed);
            len = st = ed = 0;
        }
        else if (RowState == 0) {
            len++;
            ed = BlockedCol;
            if (len > 1) {
                win ^= Grundy(len, st, ed);
                len = st = ed = 0;
            }
            else {
                st = ed;
                ed = 0;
            }
        }
        else
            len++;
    }
    win ^= Grundy(len, st, 0);
    if (win == 0)
        cout << "LOSE";
    else
        cout << "WIN";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> n;
    ReadData();
    Solve();
    return 0;
}
