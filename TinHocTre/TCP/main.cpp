#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int n;
vector<ll> a;

ll ReverseOfX(ll x) {
    ll ans = 0;
    while (x > 0) {
        ans = ans*10 + (x%10);
        x = x/10;
    }
    return ans;
}

void ReadData() {
    ll x;
    for (int i=1; i<=n; i++) {
        cin >> x;
        ll tmp = ReverseOfX(x);
        a.push_back(tmp);
    }
}

bool IsCP(ll x) {
    ll tmp = sqrt(x);
    return ((tmp*tmp) == x);
}

int Solution() {
    int ans = 0;
    for (int i=0; i<n; i++)
        if (IsCP(a[i]))
            ans++;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("tcp.inp", "r", stdin);
    freopen("tcp.out", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
