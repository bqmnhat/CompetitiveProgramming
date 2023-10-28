#include <iostream>
#include <bits/stdc++.h>
#define MaxN 400000
using namespace std;
typedef pair<int, int> pii;
int n, d, k, deg[MaxN+1], dist[MaxN+1];
vector<pii> edges;
priority_queue<pii, vector<pii>, greater<pii>> pq;

bool AddFirstD() {
    if (d >= n)
        return false;
    deg[1] = 0;
    for (int i=2; i<=d+1; i++) {
        edges.push_back(pii(i, i-1));
        deg[i]++;
        deg[i-1]++;
    }
    for (int i=1; i<=d+1; i++) {
        dist[i] = max(i-1, d-i+1);
        if (deg[i] > k)
            return false;
        else if (deg[i] < k)
            pq.push(pii(dist[i], i));
    }
    return true;
}

bool Solve() {
    if (!AddFirstD())
        return false;
    int cnt = d+1;
    while ((!pq.empty()) && (cnt < n)) {
        pii tmp = pq.top();
        pq.pop();
        if (tmp.first == d)
            break;
        int u = tmp.second;
        cnt++;
        deg[u]++;
        deg[cnt]++;
        dist[cnt] = dist[u] + 1;
        edges.push_back(pii(u, cnt));
        if(deg[u] < k)
            pq.push(tmp);
        if (deg[cnt] < k)
            pq.push(pii(dist[cnt], cnt));
    }
    if (cnt < n)
        return false;
    return true;
}

void PrintAns() {
    for (auto x: edges)
        cout << x.first << ' ' << x.second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d >> k;
    if (Solve()) {
        cout << "YES\n";
        PrintAns();
    }
    else
        cout << "NO";
    return 0;
}
