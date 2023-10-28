#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200
using namespace std;
typedef long long ll;
int n, m;
bool vis[MaxN+5][MaxN+5][MaxN+5];
ll dp[MaxN+5][MaxN+5][MaxN+5], a[MaxN+5][MaxN+5];
vector<int> dir[4] = {{1, 0, 1}, {1, 0, 0}, {0, 1, 0}, {0, 1, 1}};

void ReadData() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];
}

bool Check(int x, int y) {
    return ((x <= n) && (y <= m) && (x >= 1) && (y >= 1));
}

ll CalDp(int iA, int jA, int iB) {
    if (vis[iA][jA][iB])
        return dp[iA][jA][iB];
    vis[iA][jA][iB] = true;
    int jB = iA + jA - iB;
    ll ans = a[iA][jA] + a[iB][jB];
    ll MaxNxtMove = -1e17;
    for (int i=0; i<4; i++) {
        int NewiA = iA + dir[i][0], NewjA = jA + dir[i][1], NewiB = iB + dir[i][2];
        int NewjB = NewiA + NewjA - NewiB;
        if ((Check(NewiA, NewjA)) && (Check(NewiB, NewjB)) && ((NewiA != NewiB) || (NewjA != NewjB)))
            MaxNxtMove = max(MaxNxtMove, CalDp(NewiA, NewjA, NewiB));
    }
    if (MaxNxtMove == -1e17)
        MaxNxtMove = 0;
    ans += MaxNxtMove;
    return (dp[iA][jA][iB] = ans);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << CalDp(1, 1, 1);
    return 0;
}
