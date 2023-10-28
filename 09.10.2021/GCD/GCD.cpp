#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Ipair;
int n, k;
ll a[500001];
stack<Ipair> stkL;
stack<Ipair> stkR;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll GCD(ll a, ll b) {
    ll tmp;
    while (b != 0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

void InitStk() {
    stkL.push(Ipair(0,0));
    stkR.push(Ipair(0,0));
    for (int i=1; i<=k; i++) {
        ll PreGCD = stkL.top().second;
        ll NewGCD = GCD(PreGCD, a[i]);
        stkL.push(Ipair(a[i], NewGCD));
    }
}

ll Solution() {
    ll ans = stkL.top().second;
    for (int i=k+1; i<=n; i++) {
        ll PreGCD = stkL.top().second;
        ll NewGCD = GCD(PreGCD, a[i]);
        stkL.push(Ipair(a[i], NewGCD));
        if (stkR.size() == 1) {
            while (stkL.size() > 1) {
                ll p = stkL.top().first, PreGCDRight = stkR.top().second;
                stkL.pop();
                ll NewGCDRight = GCD(p, PreGCDRight);
                stkR.push(Ipair(p, NewGCDRight));
            }
        }
        stkR.pop();
        ans = max(ans, GCD(stkL.top().second, stkR.top().second));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("GCD.INP", "r", stdin);
    freopen("GCD.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    InitStk();
    cout << Solution();
    return 0;
}
