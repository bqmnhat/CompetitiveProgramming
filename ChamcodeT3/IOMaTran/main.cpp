#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;

void Solve() {
    ll aij;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> aij;
            cout << aij;
            if (j < m)
                cout << " ";
        }
        if (i < n)
            cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Solve();
    return 0;
}
