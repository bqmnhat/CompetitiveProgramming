#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m, trace1[10001];
queue<int> q;

void Init() {
    for (int i=1; i<=10000; i++)
        trace1[i] = -1;
}

void PrintAns() {
    int i = m, cnt = 0;
    while (i != n) {
        cnt++;
        i = trace1[i];
    }
    cout << cnt;
}

void BFS(int src) {
    q.push(src);
    trace1[src] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == m) {
            PrintAns();
            return;
        }
        int v1 = u*2;
        if ((trace1[v1] == -1) && (v1 <= 2*m)) {
            trace1[v1] = u;
            q.push(v1);
        }
        int v2 = u-1;
        if((v2 >= 1) && (trace1[v2] == -1)) {
            trace1[v2] = u;
            q.push(v2);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Init();
    BFS(n);
    cout << ' ';
    return 0;
}
