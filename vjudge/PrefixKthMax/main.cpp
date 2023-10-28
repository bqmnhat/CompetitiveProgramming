#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
using namespace std;
int n, k, p[MaxN+1];
priority_queue<int, vector<int>, greater<int>> pq;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> p[i];
}

void Solve() {
    for (int i=1; i<=k; i++)
        pq.push(p[i]);
    cout << pq.top() << '\n';
    for (int i=k+1; i<=n; i++) {
        pq.push(p[i]);
        pq.pop();
        cout << pq.top() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    Solve();
    return 0;
}
