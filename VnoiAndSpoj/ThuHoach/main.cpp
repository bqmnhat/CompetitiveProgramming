#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200
using namespace std;
typedef pair<int, int> pii;
int n, m, InWhichSCC[MaxN*MaxN+1], val[MaxN*MaxN+1], SCCVal[MaxN*MaxN+1], diri[2] = {1, 0}, dirj[2] = {0, 1}, NewN, dp[MaxN*MaxN+1];
int num[MaxN*MaxN+1], low[MaxN*MaxN+1], counter = 0;
bool found[MaxN*MaxN+1], vis[MaxN*MaxN+1];
string s[MaxN];
vector<int> g[MaxN*MaxN+1], SCCgraph[MaxN*MaxN+1];
vector<vector<int>> SCC;
stack<int> stk;

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> s[i];
}

bool Check(int x, int y) {
    return ((x >= 0) && (x < n) && (y >= 0) && (y < m));
}

void MakeGraph() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (s[i][j] == '#')
                continue;
            if ((s[i][j] >= '0') && (s[i][j] <= '9'))
                val[i*m+j] = int(s[i][j] - '0');
            for (int k=0; k<2; k++) {
                int NewI = i + diri[k], NewJ = j + dirj[k];
                if ((Check(NewI, NewJ)) && (s[NewI][NewJ] != '#'))
                    g[i*m+j].push_back(NewI*m+NewJ);
            }
            if (s[i][j] == 'W') {
                int NewI = i, NewJ = j - 1;
                if ((Check(NewI, NewJ)) && (s[NewI][NewJ] != '#'))
                    g[i*m+j].push_back(NewI*m+NewJ);
            }
            if (s[i][j] == 'N') {
                int NewI = i-1, NewJ = j;
                if ((Check(NewI, NewJ)) && (s[NewI][NewJ] != '#'))
                    g[i*m+j].push_back(NewI*m+NewJ);
            }
        }
    }
    NewN = n*m-1;
}

void DFS(int u) {
    counter++;
    num[u] = low[u] = counter;
    stk.push(u);
    for (int v: g[u]) {
        if (!found[v]) {
            if (!num[v]) {
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
            else
                low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u]) {
        int v, curId, curVal = 0;
        SCC.push_back({});
        curId = SCC.size()-1;
        do {
            v = stk.top();
            stk.pop();
            SCC[curId].push_back(v);
            InWhichSCC[v] =curId;
            found[v] = true;
            curVal += val[v];
        } while (v != u);
        SCCVal[curId] = curVal;
    }
}

void Tarjan() {
    SCC.push_back({});
    for (int i=0; i<=NewN; i++)
        if (!num[i])
            DFS(i);
    int SCCSize = SCC.size()-1;
    for (int i=1; i<=SCCSize; i++) {
        for (int u: SCC[i]) {
            for (int v: g[u]) {
                if (InWhichSCC[v] != i)
                    SCCgraph[i].push_back(InWhichSCC[v]);
            }
        }
    }
}

void DFSFindMaxVal(int u) {
    vis[u] = true;
    dp[u] = SCCVal[u];
    int MaxVal = 0;
    for (int v: SCCgraph[u]) {
        if (!vis[v])
            DFSFindMaxVal(v);
        MaxVal = max(MaxVal, dp[v]);
    }
    dp[u] += MaxVal;
}

int Solution() {
    int SCCSize = SCC.size();
    for (int i=1; i<=SCCSize; i++)
        if (!vis[i])
            DFSFindMaxVal(i);
    return dp[InWhichSCC[0]];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    MakeGraph();
    Tarjan();
    cout << Solution();
    return 0;
}
