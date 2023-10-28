#include <iostream>
#include <bits/stdc++.h>
#define MaxN 15
#define MaxM 100
using namespace std;
int t, n, m, bit[MaxM+1];
bool vis[(1 << MaxN)];

void Init() {
    for (int i=0; i<(1 << n); i++)
        vis[i] = false;
}

void ReadData() {
    for (int i=1; i<=m; i++) {
        int mask = 0;
        for (int j=n-1; j>=0; j--) {
            int tmp;
            cin >> tmp;
            mask ^= ((1 << j)*tmp);
        }
        bit[i] = mask;
    }
}

int Solution(int mask) {
    queue<int> q;
    q.push(0);
    vis[0] = true;
    int ans = -1;
    while (!q.empty()) {
        int sz = q.size();
        ans++;
        while (sz--) {
            int CurMask = q.front();
            if (CurMask == mask)
                return ans;
            q.pop();
            for (int i=1; i<=m; i++) {
                int nxtMask = (CurMask^bit[i]);
                if (!vis[nxtMask]) {
                    vis[nxtMask] = true;
                    q.push(nxtMask);
                }
            }
        }
    }
    return -1;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m;
        Init();
        ReadData();
        cout << "Case " << i << ": ";
        int ans = Solution((1 << n) - 1);
        if (ans == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("STL.INP", "r", stdin);
    freopen("STL.OUT", "w", stdout);
    cin >> t;
    Solve();
    return 0;
}
