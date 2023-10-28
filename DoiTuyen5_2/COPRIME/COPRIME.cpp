#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
#define MaxMask 512
using namespace std;
typedef bitset<100> bs;
typedef pair<int, bs> pibs;
int n, dp[MaxN+5][MaxMask+5], a[MaxN+5], d[MaxN+5], PrimeId[MaxN+5], MaxAi = 0;
bs AllAvailable, NullBs;
bool vis[MaxN+5];
unordered_map<bs, int> dpForSub2[MaxN+5];
vector<int> g[MaxN+5];

void Init() {
    for (int i=0; i<min(n, 100); i++) {
        AllAvailable[i] = 1;
        NullBs[i] = 0;
    }
    for (int i=0; i<=n; i++) {
        dpForSub2[i].clear();
        for (int j=0; j<=MaxMask; j++)
            dp[i][j] = -1;
    }
    memset(vis, false, sizeof(vis));
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        MaxAi = max(MaxAi, a[i]);
    }
}

// dp bitmask for the first subtask solution
void MakeD() {
    for (int i=2; i*i<= MaxN; i++)
        if (d[i] == 0)
            for (int j=i; i*j <= MaxN; j++)
                d[i*j] = i;
    int cnt = -1;
    for (int i=1; i<=MaxN; i++) {
        if (d[i] == 0) {
            cnt++;
            PrimeId[i] = cnt;
        }
    }
}

int GetMask(int x) {
    int mask = 0;
    while (x > 1) {
        int p = d[x];
        if (p == 0)
            p = x;
        mask |= (1 << PrimeId[p]);
        x = x/p;
    }
    return mask;
}

bs GetMaskBs(int x) {
    bs mask = 0;
    while (x > 1) {
        int p = d[x];
        if (p == 0)
            p = x;
        mask[p] = 1;
        x = x/p;
    }
    return mask;
}

int CalDpSub1(int id, int mask) {
    if ((id == n+1) || (mask == ((1 << n) - 1)))
        return 0;
    if (dp[id][mask] != -1)
        return dp[id][mask];
    int tmp = CalDpSub1(id+1, mask), tmpMask = GetMask(a[id]);
    if ((tmpMask & mask) == 0) {
        int NewMask = (mask | tmpMask);
        tmp = max(tmp, CalDpSub1(id+1, NewMask) + 1);
    }
    return dp[id][mask] = tmp;
}
//Using bitset for second subtask

int CalDpSub2(int id, bs mask) {
    if ((id == n+1) || (mask == AllAvailable))
        return 0;
    if (dpForSub2[id].find(mask) != dpForSub2[id].end())
        return dpForSub2[id][mask];
    int tmp = CalDpSub2(id+1, mask);
    bs tmpMask = GetMaskBs(a[id]);
    if ((tmpMask & mask) == NullBs) {
        bs NewMask = (mask | tmpMask);
        tmp = max(tmp, CalDpSub2(id+1, NewMask) + 1);
    }
    return dpForSub2[id][mask] = tmp;
}

// DFS and count connected components for the third subtask
void MakeG() {
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (__gcd(a[i], a[j]) != 1) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
}

void DFS(int u) {
    for (int v: g[u]) {
        if (!vis[v]) {
            vis[v] = true;
            DFS(v);
        }
    }
}

int Solution() {
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            cnt++;
            vis[i] = true;
            DFS(i);
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("COPRIME.INP", "r", stdin);
    freopen("COPRIME.OUT", "w", stdout);
    cin >> n;
    Init();
    ReadData();
    MakeD();
    if (MaxAi <= 20)
        cout << CalDpSub1(1, 0);
    else if (MaxAi <= 100) {
        cout << CalDpSub2(1, NullBs);
    }
    else {
        MakeG();
        cout << Solution();
    }
    return 0;
}
