#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
int n, m, l[MaxN+1], r[MaxN+1], x[MaxN+1], ans[MaxN+1];
set<int> StillInTournament;

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> l[i] >> r[i] >> x[i];
}

void Solve() {
    for (int i=1; i<=n; i++)
        StillInTournament.insert(i);
    vector<int> Erase;
    for (int i=1; i<=m; i++) {
        set<int>::iterator it = StillInTournament.lower_bound(l[i]);
        while (it != StillInTournament.end()) {
            int cur = *it;
            if (cur > r[i])
                break;
            if (cur != x[i]) {
                Erase.push_back(cur);
                ans[cur] = x[i];
            }
            it++;
        }
        for (auto k: Erase)
            StillInTournament.erase(k);
        Erase.clear();
    }
    for (int i=1; i<=n; i++)
        cout << ans[i] << ' ';
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
