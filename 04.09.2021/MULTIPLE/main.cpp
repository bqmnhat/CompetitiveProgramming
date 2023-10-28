#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 10000
int n, trace1[MaxN], trace2[MaxN];
queue <int> q;

void Init() {
    for (int i=0; i<MaxN; i++) {
        trace1[i] = trace2[i] = 0;
    }
    while (!q.empty())
        q.pop();
}

void PrintAns(int i) {
    string ans = "";
    while (i != -1) {
        ans = char(trace2[i] + '0') + ans;
        i = trace1[i];
    }
    cout << ans << '\n';
}

void BFS() {
    q.push(1%n);
    trace1[1%n] = -1;
    trace2[1%n] = 1;
    int u;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        if (u == 0)
            break;
        for (int i=0; i<=1; i++) {
            long long v =(u*10 + i)%n;
            if (trace1[v] == 0) {
                q.push(v);
                trace1[v] = u;
                trace2[v] = i;
            }
        }
    }
}

void Solve() {
    cin >> n;
    while (n != 0) {
        Init();
        BFS();
        PrintAns(0);
        cin >> n;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MULTIPLE.INP", "r", stdin);
    freopen("MULTIPLE.OUT", "w", stdout);
    Solve();
    return 0;
}
