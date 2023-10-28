#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10050
using namespace std;
typedef long long ll;
bool Sieve[MaxN+1];
ll cnt[MaxN+1], d[MaxN+1], p[MaxN+1], n, a[MaxN+1];

void MakeSieve() {
    for (int i=1; i<=MaxN; i++)
        d[i] = 1;
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i<=MaxN; i++) {
        if (!Sieve[i]) {
            for(int j=1; i*j<=MaxN; j++) {
                if (i != i*j)
                    Sieve[i*j] = true;
                d[i*j] *= i;
                p[i*j]++;
            }
        }
    }
}

void ReadData() {
    memset(cnt, 0, sizeof(cnt));
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i=2; i<=MaxN; i++)
        for (int j=2; i*j<=MaxN; j++)
            cnt[i] += cnt[i*j];
}

ll xC4(ll x) {
    if (x < 4)
        return 0LL;
    ll ans = (x*(x-1LL)*(x-2)*(x-3))/24;
    return ans;
}

ll Solution() {
    ll ans = xC4(n);
    if (ans == 0)
        return 0;
    for (int i=2; i<=MaxN; i++) {
        if (d[i] == i) {
            if (p[i]&1)
                ans -= xC4(cnt[i]);
            else
                ans += xC4(cnt[i]);
        }
    }
    return ans;
}

void Solve() {
    while (cin >> n) {
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeSieve();
    Solve();
    return 0;
}
