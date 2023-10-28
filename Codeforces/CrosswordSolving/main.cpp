#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int n, m;
string s, t;

void Solve() {
    vector<int> pos;
    for (int i=1; i<=n; i++)
        pos.push_back(i);
    vector<int> tmppos;
    for (int i=1; i<=m-n+1; i++) {
        tmppos.clear();
        for (int j=1; j<=n; j++)
            if (s[j] != t[i + j - 1])
                tmppos.push_back(j);
        if (tmppos.size() < pos.size())
            pos = tmppos;
    }
    cout << pos.size() << '\n';
    for (int x: pos)
        cout << x << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> t;
    s = ' ' + s;
    t = ' ' + t;
    Solve();
    return 0;
}
