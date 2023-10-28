#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int x, n, p[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> p[i];
}

void Solve() {
    set<int> pos{0, x};
    multiset<int> len{x};
    for (int i=1; i<=n; i++) {
        auto itr = pos.upper_bound(p[i]);
        auto itl = itr;
        itl--;
        len.erase(len.find(*itr - *itl));
        len.insert(p[i] - *itl);
        len.insert(*itr - p[i]);
        pos.insert(p[i]);
        auto AnsIt = len.end();
        AnsIt--;
        cout << (*AnsIt) << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> n;
    ReadData();
    Solve();
    return 0;
}
