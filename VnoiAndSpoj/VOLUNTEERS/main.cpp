#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
int n, m, b[MaxN+1];
multiset<int, greater<int>> a;
const int INF = 1e9+7;

void ReadData() {
    for (int i=1; i<=n; i++) {
        int ai;
        cin >> ai;
        a.insert(ai);
    }
    for (int i=1; i<=m; i++)
        cin >> b[i];
}

int Solution() {
    a.insert(0);
    for (int i=1; i<=m; i++) {
        auto it = a.lower_bound(b[i]);
        if ((*it) != 0)
            a.erase(it);
    }
    auto it = a.lower_bound(INF);
    if ((*it) != 0)
        return (*it);
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
