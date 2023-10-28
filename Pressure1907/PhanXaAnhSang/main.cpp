#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int t, n, CurI[4] = {0, 0, 1, -1}, CurJ[4] = {-1, 1, 0, 0};
string s[MaxN+1];
bool vis[MaxN+1][MaxN+1];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> s[i];
}

bool InBound(int x, int y) {
    return ((x < n) && (x >= 0) && (y < n) && (y >= 0));
}

int DirChangeLR(int Dir) {
    if (Dir == 0)
        return 3;
    else if (Dir == 1)
        return 2;
    else if (Dir == 2)
        return 1;
    return 0;
}

int DirChangeRL(int Dir) {
    if (Dir == 0)
        return 2;
    else if (Dir == 1)
        return 3;
    else if (Dir == 2)
        return 0;
    return 1;
}

int Solution() {
    memset(vis, false, sizeof(vis));
    int i = 0, j = 0, curDir = 1, ans = 0;
    while (InBound(i, j)) {
        if (s[i][j] == '2') {
            curDir = DirChangeLR(curDir);
            if (!vis[i][j]) {
                ans++;
                vis[i][j] = true;
            }
        }
        else if (s[i][j] == '1') {
            curDir = DirChangeRL(curDir);
            if (!vis[i][j]) {
                ans++;
                vis[i][j] = true;
            }
        }
        i += CurI[curDir];
        j += CurJ[curDir];
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
