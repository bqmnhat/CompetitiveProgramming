#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int parents[801], n, m, ChosenStudents = 0, tmpAns[801], lt = 0;
bool visited[801], mark[801];
vector<int> g[801];
stack<int> st;

void addedge(int u, int v) {
    g[u].push_back(v);
}

void DFSMES(int s) {
    st.push(s);
    visited[s] = true;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (auto v: g[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

int Solution() {
    for (int u=1; u<=n; u++) {
        if (!visited[u]) {
            mark[u] = true;
            DFSMES(u);
        }
    }
    for (int i=1; i<=n; i++)
        visited[i] = false;
    int ans = 0;
    for (int u=n; u>=1; u--) {
        if ((mark[u]) && (!visited[u])) {
            ans++;
            DFSMES(u);
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        addedge(u,v);
    }
    cout << Solution();
    return 0;
}
