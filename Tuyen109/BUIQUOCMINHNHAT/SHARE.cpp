#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100010
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
int n;
ll m, Sum = 0;
pii a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].first;
        Sum += a[i].first;
        a[i].second = i;
    }
}

bool CmpPiiSecond(pii a, pii b) {
    return (a.second < b.second);
}

void Solve() {
    if (Sum < m) {
        cout << "-1";
        return;
    }
    if (Sum == m) {
        for (int i=1; i<=n; i++)
            cout << a[i].first << ' ';
        return;
    }
    sort(a+1, a+1+n, greater<pii>());
    ll Minus = 0;
    int i, MinusUntil = 0;
    for (i=2; i<=n+1; i++) {
        if (a[i].first != a[i-1].first) {
            ll cost = 1LL*(i-1LL)*(a[i-1].first - a[i].first);
            if ((Sum - cost) >= m) {
                Sum -= cost;
                Minus += a[i-1].first - a[i].first;
                MinusUntil = i-1;
            }
            else
                break;
        }
    }
    ll tmp1 = (Sum - m)/(1LL*(i-1LL));
    ll tmp2 = (Sum - m)%(1LL*(i-1LL));
    for (int j=1; j<=tmp2; j++)
        a[j].first -= 1LL;
    for (int j=1; j<=MinusUntil; j++)
        a[j].first -= Minus;
    for (int j=1; j<i; j++)
        a[j].first -= tmp1;
    sort(a+1, a+1+n, CmpPiiSecond);
    for (int i=1; i<=n; i++)
        cout << a[i].first << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SHARE.INP", "r", stdin);
    freopen("SHARE.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
