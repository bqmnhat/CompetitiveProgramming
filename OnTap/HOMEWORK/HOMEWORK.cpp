#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m, t[101],sum = 0;
int tk[101];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sum = sum + t[i];
    }
    int a,b;
    for (int i=1; i<=m; i++) {
        cin >> a >> b;
        tk[a] = 1;
    }
}

void Solve() {
    int Max = 0;
    for (int i=1; i<=n; i++) {
        if ((tk[i] == 0) && (t[i] > Max)) {
            Max = t[i];
        }
    }
    cout << sum - Max;
}

int main()
{
    freopen("HOMEWORK.INP", "r", stdin);
    freopen("HOMEWORK.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
