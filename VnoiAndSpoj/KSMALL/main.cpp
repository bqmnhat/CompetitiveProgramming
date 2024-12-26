#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
typedef long long ll;
int n, k;
ll a[MaxN+5], b[MaxN+5];
vector<ll> c;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
        cin >> b[i];
}

void Solve() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            ll tmp = a[i]*b[j];
            c.push_back(tmp);
        }
    }
    sort(c.begin(), c.end());
    for (int i=0; i<k; i++)
        cout << c[i] << ' ';
}

int main()
{
    freopen("KSMALL.INP", "r", stdin);
    freopen("KSMALL.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    Solve();
    return 0;
}
