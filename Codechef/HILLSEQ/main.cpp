#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, a[100001], b[100002], lb = 0;
map <long long, long long> m;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
}

void Solve() {
    bool CanPrint = true;
    auto x = m.rbegin();
    if (x->second >= 2)
        CanPrint = false;
    for (auto it : m)
        if (it.second > 2)
            CanPrint = false;
    if (CanPrint) {
        for (auto it : m)
            if (it.second == 2)
                cout << it.first << " ";
        for (auto it = m.rbegin(); it != m.rend(); it++) {
            cout << it->first << " ";
        }
    }
    else
        cout << -1;
    cout << '\n';
    m.clear();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        lb = 0;
        ReadData();
        Solve();
    }
    return 0;
}
