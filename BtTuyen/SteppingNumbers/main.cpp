#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[1000001], la = 0;
bool visited[1000001];
int n,m;
queue<int> q;

void BFS(long long st) {
    q.push(st);
    while (!q.empty()) {
        long long u = q.front();
        q.pop();
        if ((u >= n) && (u <= m) && (!visited[u])) {
            visited[u] = true;
            la++;
            a[la] = u;
        }
        long long v1 = (u*10 + ((u%10) - 1)), v2 = (u*10 + ((u%10) + 1));
        if ((!visited[v1]) && (v1 <= m) && (v1 >= n)) {
            q.push(v1);
        }
        if ((!visited[v2]) && (v2 <= m) && (v2 >= n)) {
            q.push(v2);
        }
    }
}

void PrintAns() {
    sort(a+1, a+1+la);
    for (int i=1; i<=la; i++)
        cout << a[i] << " ";
}

int main()
{
    cin >> n >> m;
    for (int i=0; i<=9; i++)
        BFS(i);
    PrintAns();
    return 0;
}
