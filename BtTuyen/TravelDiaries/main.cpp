#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Ipair;
int n, m, a[1001][1001], di[5] = {0, -1, 0, 1, 0}, dj[9] = {0, 0, 1, 0, -1};
queue <Ipair> q;

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2)
                q.push(make_pair(i,j));
        }
    }
}

bool Check(int u, int v) {
    return ((u >= 1) && (u <= n) && (v >= 1) && (v <= m));
}

int Solution() {
    int ans = 0;
    while (!q.empty()) {
        int qsize = q.size();
        while (qsize--) {
            Ipair p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            for (int t=1; t<=4; t++) {
                int u = i+di[t], v = j+dj[t];
                if ((Check(u,v)) && (a[u][v] == 1)) {
                    a[u][v] = 2;
                    q.push(make_pair(u,v));
                }
            }
        }
        ans++;
    }
    return ans-1;
}

int main()
{
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
