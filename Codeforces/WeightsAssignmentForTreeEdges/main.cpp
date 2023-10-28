#include <iostream>
#include <bits/stdc++.h>
int t,n,b[200001], p[200001], dist[200001];

using namespace std;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> b[i];
    for (int i=1; i<=n; i++)
        cin >> p[i];
    for (int i=1; i<=n; i++)
        dist[i] = -1;
}

void Solve() {
    if (b[p[1]] != p[1]) {
        cout << -1 << '\n';
        return;
    }
    dist[p[1]] = 0;
    for (int i=2; i<=n; i++) {
        if (dist[b[p[i]]] == -1) {
            cout << -1 << '\n';
            return;
        }
        else
            dist[p[i]] = dist[p[i-1]] + 1;
    }
    for (int i=1; i<=n; i++)
        cout << dist[i] - dist[b[i]] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        Solve();
    }
    return 0;
}
