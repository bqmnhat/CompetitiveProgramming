#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
ll a[MaxN+5], Sum = 0;
int n;

void ReadData() {
    memset(a, 0, sizeof(a));
    Sum = 0;
    for (int i=1; i<=n; i++) {
        ll cost;
        for (int j=1; j<=n; j++) {
            cin >> cost;
            Sum += cost;
            a[j] += cost;
            a[i] -= cost;
        }
    }
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=n; i++)
        ans += max(0LL, a[i]);
    return ans;
}

void Solve() {
    int cnt = 0;
    while ((cin >> n) && (n != 0LL)) {
        ReadData();
        cnt++;
        cout << cnt << ". " << Sum << ' ' << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
