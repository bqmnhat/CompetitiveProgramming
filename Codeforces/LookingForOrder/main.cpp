#include <iostream>
#include <bits/stdc++.h>
#define MaxN 25
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll dp[(1 << MaxN)], dist[MaxN+2][MaxN+2];
int n;
vector<int> path;
pii a[MaxN+1];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> a[i].first >> a[i].second;
}

ll CalDist(pii f, pii t) {
    int fx = f.first, fy = f.second, tx = t.first, ty = t.second;
    ll DistX = abs(fx - tx);
    ll DistY = abs(fy - ty);
    return (DistX*DistX + DistY*DistY);
}

void MakeDist() {
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            if (i == j)
                continue;
            dist[i][j] = CalDist(a[i], a[j]);
        }
    }
}

ll Solution() {
    for (int mask = 0; mask < (1 << n); mask++)
        dp[mask] = 1e18;
    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i=0; i<n; i++) {
            if (mask&(1 << i))
                continue;
            int NxtMask = (mask|(1 << i));
            if (NxtMask > (1 << n) - 1)
                continue;
            dp[NxtMask] = min(dp[NxtMask], dp[mask] + (dist[n][i] << 1LL));
            for (int j=0; j<n; j++) {
                if (i == j)
                    continue;
                if (mask&(1 << j))
                    continue;
                int NxtMask2 = (NxtMask | (1 << j));
                if (NxtMask2 > (1 << n) - 1)
                    continue;
                dp[NxtMask2] = min(dp[NxtMask2], dp[mask] + dist[n][i] + dist[i][j] + dist[j][n]);
                break;
            }
        }
    }
    return dp[(1 << n) - 1];
}

void FindPath(int CurMask) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if ((CurMask&(1 << i)) && (CurMask&(1 << j)) && (dp[CurMask^(1 << i)^(1 << j)] == dp[CurMask] - dist[n][i] - dist[i][j] - dist[j][n])) {
                path.push_back(0);
                path.push_back(i+1);
                path.push_back(j+1);
                FindPath(CurMask^(1 << i)^(1 << j));
                return;
            }
        }
        if ((CurMask&(1 << i)) && (dp[CurMask^(1 << i)] == dp[CurMask] - dist[n][i]*2)) {
            path.push_back(0);
            path.push_back(i+1);
            FindPath(CurMask^(1 << i));
            return;
        }
    }
}

void PrintAns() {
    path.push_back(0);
    reverse(path.begin(), path.end());
    for (int t: path)
        cout << t << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int sx, sy;
    cin >> sx >> sy >> n;
    a[n].first = sx;
    a[n].second = sy;
    ReadData();
    MakeDist();
    cout << Solution() << '\n';
    FindPath((1 << n) - 1);
    PrintAns();
    return 0;
}
