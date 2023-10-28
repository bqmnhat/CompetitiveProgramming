#include <iostream>
#include <bits/stdc++.h>
#define MaxM 15
using namespace std;
typedef long long ll;
ll n, a[MaxM+1];
int m;

void ReadData() {
    for (int i=0; i<m; i++)
        cin >> a[i];
}

ll LCM(ll a, ll b) {
    ll g = __gcd(a, b);
    ll ans = (a*b)/g;
    return ans;
}

ll CalCancel(int x) {
    int NO1 = 0, cnt = -1;
    ll lcm = 1;
    while (x > 0) {
        cnt++;
        int tmp = (x&1);
        if (tmp == 1) {
            NO1++;
            lcm = LCM(lcm, a[cnt]);
        }
        x >>= 1;
    }
    if (NO1&1)
        return (n/lcm);
    return (-1LL*(n/lcm));
}

ll Solution() {
    ll ans = n, tmp = (1LL << m);
    for (int i=1; i < tmp; i++)
        ans = ans - CalCancel(i);
    return ans;
}

void Solve() {
    while (cin >> n >> m) {
        ReadData();
        cout << Solution() << '\n';
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
