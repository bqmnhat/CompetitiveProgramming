#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int n, m, t[MaxN+5];
multiset<int> tickets;

void ReadData() {
    for (int i=1; i<=n; i++) {
        int hi;
        cin >> hi;
        tickets.insert(hi);
    }
    for (int i=1; i<=m; i++)
        cin >> t[i];
}

void Solve() {
    for (int i=1; i<=m; i++) {
        if (tickets.empty()) {
            cout << "-1\n";
            continue;
        }
        auto it = tickets.lower_bound(t[i]);
        if (it == tickets.end())
            it--;
        if ((*it) > t[i]) {
            if (it == tickets.begin()) {
                cout << "-1\n";
                continue;
            }
            it--;
        }
        cout << (*it) << '\n';
        tickets.erase(it);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
