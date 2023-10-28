#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[35][35], dy[4] = {-1,0,1,0}, dx[4] = {0,-1,0,1};
bool visited[35][35];

void ReadData() {
    char c;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> c;
            if (c == '#') {
                a[i][j] = 1;
            }
        }
    }
}

void BuildMargin() {
    for (int i=2; i<=n; i++) {
        a[0][i] = 1;
    }
    for (int i=2; i<=n; i++) {
        a[i][0] = 1;
    }
    for (int i=1; i<n; i++) {
        a[n+1][i] = 1;
    }
    for (int i=1; i<n; i++) {
        a[i][n+1] = 1;
    }
}

bool check(int x, int y) {
    return ((x>=1) && (x<=n) && (y>=1) && (y<=n));
}

int MirrorArea(int x, int y) {
    visited[x][y] = true;
    int cnt = 0;
    if (a[x-1][y] == 1)
        cnt+=9;
    if (a[x][y-1] == 1)
        cnt+=9;
    if (a[x+1][y] == 1)
        cnt+=9;
    if (a[x][y+1] == 1)
        cnt+=9;
    for (int i=0; i<4; i++) {
        int u = x + dx[i], v = y + dy[i];
        if ((a[u][v] == 0) && (!visited[u][v]) && (check(u,v))) {
            cnt = cnt + MirrorArea(u,v);
        }
    }
    return cnt;
}

int Solution() {
    int ans = MirrorArea(1,1);
    if (!visited[n][n])
        ans += MirrorArea(n,n);
    return ans;
}

int main()
{
    freopen("MIRROR.INP", "r", stdin);
    freopen("MIRROR.OUT", "w", stdout);
    cin >> n;
    ReadData();
    BuildMargin();
    cout << Solution();
    return 0;
}
