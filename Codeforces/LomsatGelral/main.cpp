#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, c[MaxN+1];
vector<int> graph[MaxN+1];

void ReadGraph() {
    int u,v;
    for (int i = 1; i<n; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
