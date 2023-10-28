#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
#define MaxMask 20000
using namespace std;
typedef bitset<18> bs;
typedef pair<int, int> pii;
int n, d[MaxN+5], PrimeId[MaxN+5], NxtId[MaxN+5], dp[MaxN+5][MaxMask];
pii a[MaxN+5];
vector<int> PrimesOfAi[MaxN+5];
//bs AllAvailable, NullBs;
//unordered_map<bs, int> dpForSub2[MaxN+5];

void Init() {
    /*for (int i=0; i<min(n, 18); i++) {
        AllAvailable[i] = 1;
        NullBs[i] = 0;
    }*/
    for (int i=0; i<=n; i++) {
        //dpForSub2[i].clear();
        for (int j=0; j<=MaxMask; j++)
            dp[i][j] = -1;
    }
}

void MakeD() {
    for (int i=2; i*i<= MaxN; i++)
        if (d[i] == 0)
            for (int j=i; i*j <= MaxN; j++)
                d[i*j] = i;
    int cnt = -1;
    for (int i=1; i<=sqrt(MaxN); i++) {
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
        if (p <= 41)
            mask |= (1 << PrimeId[p]);
        x = x/p;
    }
    return mask;
}

int GetMaxP(int x) {
    int MaxP = 0;
    while (x > 1) {
        int p = d[x];
        if (p == 0)
            p = x;
        MaxP = max(MaxP, p);
        x = x/p;
    }
    return MaxP;
}

/*vector<int> GetFullMask(int x) {
    vector<int> res;
    bool vis[MaxN+5];
    memset(vis, false, sizeof(vis));
    res.clear();
    while (x > 1) {
        int p = d[x];
        if (p == 0)
            p = x;
        if (!vis[p]) {
            vis[p] = true;
            res.push_back(p);
        }
        x = x/p;
    }
    sort(res.begin(), res.end());
    return res;
}*/

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].second;
        a[i].first = GetMaxP(a[i].second);
    }
}

/*void FindPrimesOfAi() {
    for (int i=1; i<=n; i++)
        PrimesOfAi[i] = GetFullMask(a[i]);
}*/

/*bool CheckSamePrimes(const vector<int>& p1, const vector<int>& p2) {
    int i=0, j=0, l1=p1.size(), l2=p2.size();
    while ((i < l1) && (j < l2)) {
        if (p1[i] == p2[j])
            return false;
        else if (p1[i] > p2[j])
            j++;
        else if (p1[i] < p2[j])
            i++;
    }
    return true;
}*/

void FindNxtId() {
    for (int i=1; i<=n; i++) {
        int j = i + 1;
        while ((j <= n) && (a[i].first == a[j].first))
            j++;
        NxtId[i] = j;
    }
}

// dp bitmask for the first subtask solution

/*bs GetMaskBs(int x) {
    bs mask = 0;
    while (x > 1) {
        int p = d[x];
        if (p == 0)
            p = x;
        if (p <= sqrt(MaxN))
            mask[PrimeId[p]] = 1;
        x = x/p;
    }
    return mask;
}*/

int CalDpSub1(int id, int mask) {
    if ((id == n+1) || (mask == ((1 << n) - 1)))
        return 0;
    if (dp[id][mask] != -1)
        return dp[id][mask];
    int tmp = CalDpSub1(id+1, mask), tmpMask = GetMask(a[id].second);
    if ((tmpMask & mask) == 0) {
        int NewMask = (mask | tmpMask);
        tmp = max(tmp, CalDpSub1(NxtId[id], NewMask) + 1);
    }
    return dp[id][mask] = tmp;
}
//Using bitset for second subtask

/*int CalDpSub2(int id, bs mask) {
    if ((id == n+1) || (mask == AllAvailable))
        return 0;
    if (dpForSub2[id][mask] != 0)
        return dpForSub2[id][mask];
    int tmp = CalDpSub2(id+1, mask);
    bs tmpMask = GetMaskBs(a[id].second);
    if ((tmpMask & mask) == NullBs) {
        bs NewMask = (mask | tmpMask);
        tmp = max(tmp, CalDpSub2(NxtId[id], NewMask) + 1);
    }
    return dpForSub2[id][mask] = tmp;
}*/

// DFS and count connected components for the third subtask
/*void MakeG() {
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
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("COPRIME.INP", "r", stdin);
    //freopen("COPRIME.OUT", "w", stdout);
    cin >> n;
    Init();
    MakeD();
    ReadData();
    sort(a+1, a+1+n);
    FindNxtId();
    cout << CalDpSub1(1, 0);
    return 0;
}
