#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, ans[1000001][4], la = 0;
map <int, int> m;
priority_queue <pair<int,int>> pq;

void ReadData() {
    int ai;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        m[ai]++;
    }
}

void PrintAns() {
    cout << la << '\n';
    for (int i=1; i<=la; i++) {
        for (int j=1; j<=3; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}

void Solve() {
    for (auto& it : m)
        pq.push(make_pair(it.second, it.first));
    while (pq.size() >= 3) {
        pair<int, int> a[4];
        for (int i=1; i<=3; i++) {
            a[i] = pq.top();
            pq.pop();
        }
        la++;
        for (int i=1; i<=3; i++) {
            ans[la][i] = a[i].second;
            a[i].first--;
            if (a[i].first > 0)
                pq.push(a[i]);
        }
    }
    PrintAns();
}

int main()
{
    freopen("Bai9.INP", "r", stdin);
    freopen("Bai9.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
