#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000005
#define SuperMax 1000000000000
using namespace std;
typedef long long ll;
int n;
vector<ll>p;
ll l, r;
bool Sieve[MaxN+1];

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i*i<=MaxN; i++)
        if (!Sieve[i])
            for (int j=i; i*j<=MaxN; j++)
                Sieve[i*j] = true;
    for (int i=2; i<=MaxN; i++)
        if (!Sieve[i])
            p.push_back(i);
}

ll SmallerEqualToThanExp(ll val, ll r) {
    ll ans = 0, CurVal = 1;
    while (CurVal <= r) {
        CurVal *= val;
        ans++;
    }
    return ans-1LL;
}

ll SmallerThanExp(ll val, ll r) {
    ll ans = 0, CurVal = 1;
    while (CurVal < r) {
        CurVal *= val;
        ans++;
    }
    return ans;
}

ll Solution() {
    ll ans = 0;
    for (int i=0; i<p.size(); i++) {
        ll tmp2 = SmallerEqualToThanExp(p[i], r), tmp1 = SmallerThanExp(p[i], l);
        ll tmp = tmp2 - tmp1 + 1LL;
        if (tmp2 <= 1)
            break;
        ans += tmp;
        if (tmp1 == 0LL)
            ans-=2;
        if (tmp1 == 1LL)
            ans--;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=n; i++) {
        cin >> l >> r;
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeSieve();
    cin >> n;
    Solve();
    return 0;
}
