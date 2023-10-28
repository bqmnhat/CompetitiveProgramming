#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
#define MaxDis 1000000
using namespace std;
typedef pair<int, int> pii;
int n, p, l, t;
pii Stops[MaxN+1];
priority_queue<int> pq;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> Stops[i].first >> Stops[i].second;
}

int Solution() {
    int ans = 0, i = 1;
    sort(Stops+1, Stops+1+n, greater<pii>());
    while (true) {
        l -= p;
        if (l <= 0)
            return ans;
        while ((i <= n) && (Stops[i].first >= l)) {
            pq.push(Stops[i].second);
            i++;
        }
        if (pq.empty())
            return -1;
        p = pq.top();
        pq.pop();
        ans++;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        while (!pq.empty())
            pq.pop();
        cin >> n;
        ReadData();
        cin >> l >> p; // l: dist; p: unit
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
