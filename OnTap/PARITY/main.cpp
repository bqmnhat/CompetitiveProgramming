#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[100001];
int n, tk[200001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void Solve() {
    int ans = 0, c = 100000;
    tk[100000] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2 == 0)
            c++;
        else
            c--;
        ans = ans + tk[c];
        tk[c]++;
    }
    cout << ans;
}

int main()
{
    freopen("PARITY.INP", "r", stdin);
    freopen("PARITY.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
