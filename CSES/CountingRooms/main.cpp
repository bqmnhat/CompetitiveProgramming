#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int n, m, diri[4] = {0, -1, 0, 1}, dirj[4] = {-1, 0, 1, 0};
string a[MaxN+5];
bool vis[MaxN+5][MaxN+5];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> a[i];
}

bool Check(int x, int y) {
    return ((x >= 0) && (x < n) && (y >= 0) && (y < m));
}

void DFSCnt(int x, int y) {
    for (int i=0; i<4; i++) {
        int NewX = x + diri[i], NewY = y + dirj[i];
        if ((Check(NewX, NewY)) && (!vis[NewX][NewY])
        && (a[NewX][NewY] == '.')) {
            vis[NewX][NewY] = true;
            DFSCnt(NewX, NewY);
        }
    }
}

int Solution() {
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if ((!vis[i][j]) && (a[i][j] == '.')) {
                vis[i][j] = true;
                ans++;
                DFSCnt(i, j);
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
