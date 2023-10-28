#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200010
using namespace std;
typedef pair<int, int> pii;
int n, A, B, Down[MaxN+1], h[MaxN+1], FromB[MaxN+1];
vector<int> path, g[MaxN+1];
vector<pii> d[MaxN+1];

inline void ReadData() {
    int u,v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFSHeight(int u, int p, int height) {
    h[u] = height;
    for (int v: g[u])
        if (v != p)
            DFSHeight(v, u, height+1);
}

bool DFSFindPath(int u, int p) {
    if (u == B) {
        path.push_back(u);
        return true;
    }
    for (int v: g[u]) {
        if (v == p)
            continue;
        if (DFSFindPath(v, u)) {
            path.push_back(u);
            return true;
        }
    }
    return false;
}

void FindPathAToB() {
    DFSFindPath(A, -1);
    reverse(path.begin(), path.end());
}

void DFSDownDp(int u, int p) {
    Down[u] = 1;
    for (int v: g[u]) {
        if (v == p)
            continue;
        DFSDownDp(v, u);
        d[u].push_back(pii(Down[v], v));
    }
    sort(d[u].begin(), d[u].end(), greater<pii>());
    if (d[u].size() > 0)
        Down[u] = d[u][0].first + 1;
}

int Solution() {
    DFSHeight(A, -1, 0);
    FindPathAToB();
    DFSDownDp(A, -1);
    path.push_back(-1);
    int l = path.size()-1, ans = 0;
    for (int i=l-1; i>=1; i--) {
        int u = path[i], nxtu = path[i+1];
        int tmpans = h[B] - h[u] + 1;
        if (d[u].size() > 0) {
            if (d[u][0].second != nxtu)
                tmpans += d[u][0].first;
            else if (d[u].size() > 1)
                tmpans += d[u][1].first;
        }
        FromB[i] = max(FromB[i+1], tmpans);
    }
    for (int i=1; i<l; i++) {
        int u = path[i], pu = path[i-1];
        int tmpans = h[pu] + 1;
        if (d[pu].size() > 0) {
            if (d[pu][0].second != u)
                tmpans += d[pu][0].first;
            else if (d[pu].size() > 1)
                tmpans += d[pu][1].first;
        }
        ans = max(ans, min(tmpans, FromB[i]));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cin >> A >> B;
    cout << Solution();
    return 0;
}
