#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T, x, pow10[301];
pair <int, int> mark[10001];
queue <int> q;

void Init() {
    for (int i=0; i<=10000; i++) {
        mark[i].first = mark[i].second = -1;
    }
    while (!q.empty())
        q.pop();
}

void PrintAns(int Cnt8, int Cnt6) {
    for (int i=1; i<=Cnt8; i++)
        cout << "8";
    for (int i=1; i<=Cnt6; i++)
        cout << "6";
}

void MakePow() {
    pow10[0] = 1;
    for (int i=1; i<=200; i++) {
        pow10[i] = ((pow10[i-1]%x)*(10%x))%x;
    }
}

void BFS() {
    mark[6%x].first = 0;
    mark[6%x].second = 1;
    mark[8%x].first = 1;
    mark[8%x].second = 0;
    q.push(6%x);
    q.push(8%x);
    bool exist = false;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if ((u == 0) && (mark[u].first + mark[u].second <= 200)) {
            PrintAns(mark[u].first, mark[u].second);
            exist = true;
            break;
        }
        int v6 = ((u*10) + 6)%x, v8 = (8*pow10[mark[u].first + mark[u].second] + u)%x;
        if ((mark[v6].first == -1) && (mark[v6].second == -1)) {
            mark[v6].first = mark[u].first;
            mark[v6].second = mark[u].second + 1;
            q.push(v6);
        }
        if ((mark[v8].first == -1) && (mark[v8].second == -1)) {
            mark[v8].first = mark[u].first+1;
            mark[v8].second = mark[u].second;
            q.push(v8);
        }
    }
    if (!exist)
        cout << "-1";
}

void Solve() {
    for (int i=1; i<=T; i++) {
        cin >> x;
        Init();
        MakePow();
        BFS();
        cout << '\n';
    }
}

int main()
{
    freopen("NUM86.INP", "r", stdin);
    freopen("NUM86.OUT", "w", stdout);
    cin >> T;
    Solve();
    return 0;
}
