#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
ll a[100001];

ll GCD(ll a, ll b) {
    ll tmp;
    while (b != 0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

ll LCM(ll a, ll b) {
    ll ans = (a*b)/GCD(a,b);
    return ans;
}

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

bool Deletable() {
    ll lcm = 1;
    for (int i=1; i<=n; i++) {
        lcm = LCM(lcm, i+1);
        if (a[i] % lcm == 0)
            return false;
    }
    return true;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        if (Deletable())
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
