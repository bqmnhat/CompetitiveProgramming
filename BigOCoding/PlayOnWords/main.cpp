#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T, n, DegIn[27], DegOut[27], Edge[27][27];
vector<int> graph[27], path;
bool vis[27];

void ReadData() {
    string tmp;
    for (int i=1; i<=n; i++) {
        cin >> tmp;
        int v = int(tmp[tmp.length()-1] - 'a'), u = int(tmp[0] - 'a');
        vis[v] = vis[u] = true;
        DegIn[v]++;
        DegOut[u]++;
        Edge[u][v] = 1;
        Edge[v][u] = 1;
        graph[u].push_back(v);
    }
}

void Init() {
    path.clear();
    for (int i=0; i<26 ; i++) {
        graph[i].clear();
        DegIn[i] = DegOut[i] = 0;
        vis[i] = true;
    }
    for (int i=0; i<26; i++)
        for (int j=0; j<26; j++)
            Edge[i][j] = 0;
}

void DFS(int u) {
    vis[u] = true;
    for (int v = 0; v < 26; v++)
        if (((Edge[u][v] > 1) || (Edge[v][u] > 1)) && (!vis[v]))
            DFS(v);
}

bool ExistEuler() {
    int u = -1, v = -1, cc = 0;
    for (int i = 0; i < 26; i++) {
        if (!vis[i]) {
            DFS(i);
            cc++;
        }
    }
    if (cc > 1)
        return false;
    for (int i=0; i<26; i++) {
        if (DegIn[i] != DegOut[i]) {
            if (u == -1)
                u = i;
            else if (v == -1)
                v = i;
            else
                return false;
        }
    }
    if (u == -1)
        return true;
    if (((DegIn[u] - DegOut[u] == 1) && (DegOut[v] - DegIn[v] == 1)) || ((DegOut[u] - DegIn[u] == 1) && (DegIn[v] - DegOut[v] == 1)))
        return true;
    return false;
}

void Solve() {
    for (int i=1; i<=T; i++) {
        cin >> n;
        Init();
        ReadData();
        if(ExistEuler())
            cout << "Ordering is possible.\n";
        else
            cout << "The door cannot be opened.\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    Solve();
    return 0;
}
