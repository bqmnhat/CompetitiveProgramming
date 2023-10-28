#include <iostream>
#include <bits/stdc++.h>
#define MAXN 500001
using namespace std;
int n, m, num[MAXN], low[MAXN], cnter = 0, la, ans[MAXN];
map <string, int> encode;
map<int, string> decode;
vector<int> graph[26];
stack<int> stk;
bool Found[MAXN];

void ReadData() {
    int id = 0;
    string s1,s2;
    for (int i=1; i<=m; i++) {
        cin >> s1 >> s2;
        if (encode.find(s1) == encode.end()) {
            encode[s1] = ++id;
            decode[id] = s1;
        }
        int id1 = encode[s1];
        if (encode.find(s2) == encode.end()) {
            encode[s2] = ++id;
            decode[id] = s2;
        }
        int id2 = encode[s2];
        graph[id1].push_back(id2);
    }
}

void Init() {
    encode.clear();
    decode.clear();
    for (int i=1; i<=MAXN-1; i++) {
        num[i] = low[i] = 0;
        Found[i] = false;
    }
    for (int i=1; i<=25; i++)
        graph[i].clear();
}

void DFS(int u) {
    num[u] = low[u] = ++cnter;
    stk.push(u);
    for (auto v: graph[u]) {
        if (!Found[v]) {
            if (num[v])
                low[u] = min(low[u], num[v]);
            else {
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    la = 0;
    if (num[u] == low[u]) {
        int v;
        do {
            v = stk.top();
            stk.pop();
            ans[++la] = v;
            Found[v] = true;
        } while (v != u);
        cout << decode[ans[la]];
        for (int i=la-1; i>=1; i--)
            cout << ", " << decode[ans[i]];
        cout << '\n';
    }
}

void Tarjan() {
    for (int i=1; i<=n; i++)
        if (!num[i])
            DFS(i);
}

void Solve() {
    cin >> n >> m;
    int t = 0;
    while ((n != 0) || (m != 0)) {
        t++;
        Init();
        ReadData();
        cout << "Calling circles for data set " << t << ":\n";
        Tarjan();
        cout << '\n';
        cin >> n >> m;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
