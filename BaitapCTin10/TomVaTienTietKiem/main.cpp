#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, la = 0;
ll v[300001], ans[300001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> v[i];
}

void Solve() {
    sort(v+1, v+1+n);
    for (int i=1; i<=n; i++) {
        if (v[i] != v[i-1]) {
            la++;
            ans[la] = v[i];
        }
    }
    cout << la << '\n';
    for (int i=1; i<=la; i++) {
        cout << ans[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
