#include <iostream>
#include <bits/stdc++.h>
#define MaxNSub2 1000
#define MaxN 300000
using namespace std;
typedef long long ll;
int n, MaxInSub[MaxN+1];
ll k, a[MaxNSub2+1], CyLen = 0, InCy[MaxNSub2+1], ToCy = 0;
vector<int> g[MaxNSub2+1], cy;

void ReadGraph() {
    int u, v;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int DFSMaxVal(int u, int p, int& NextCur) {
    int MaxID = 0;
    ll MaxVal = -2e9;
    int deg = 0;
    for (int v: g[u]) {
        if (v == p)
            continue;
        deg++;
        int tmpNextID = 0;
        int tmp = DFSMaxVal(v, u, tmpNextID);
        if (tmp > MaxVal) {
            MaxVal = tmp;
            MaxID = tmpNextID;
        }
        else if ((tmp == MaxVal) && (tmpNextID < MaxID))
            MaxID = tmpNextID;
    }
    if (deg == 0) {
        NextCur = u;
        return a[u]-1LL;
    }
    NextCur = MaxID;
    return MaxVal - 1LL;
}

void CycleProcessing() {
    int cur = 1, cnt = 0;
    do {
        cy.push_back(cur);
        InCy[cur] = cnt;
        cnt++;
        int NextCur = 0;
        DFSMaxVal(cur, -1, NextCur);
        cur = NextCur;
    } while (!InCy[cur]);
    ToCy = InCy[cur] - 1LL;
    CyLen = cnt - InCy[cur] + 1LL;
}

int Solution() {
    k++;
    if (k <= ToCy)
        return cy[k];
    k = (k-ToCy-1)%CyLen;
    return cy[k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadGraph();
    CycleProcessing();
    cout << Solution();
    return 0;
}
