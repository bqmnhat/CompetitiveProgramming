#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int t, cntsqr[MaxN+1], cntprime[MaxN+1], d[MaxN+1];
bool Sieve[MaxN+1];
map <int, ll> mu;

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i*i<=MaxN; i++)
        if (Sieve[i] == false)
            for (int j=i; i*j <= MaxN; j++)
                Sieve[i*j] = true;
}

void MakeD() {
    for (int i=2; i*i<=MaxN; i++)
        if (d[i] == 0)
            for (int j=i; i*j <= MaxN; j++)
                d[i*j] = i;
}

ll CntDiv(int x) {
    mu.clear();
    while (x > 1) {
        int p = d[x];
        if (p == 0)
            p = x;
        mu[p]++;
        x = x/p;
    }
    ll ans = 1;
    for (auto i = mu.begin(); i!= mu.end(); i++)
        ans = ans*(((*i).second*2) + 1);
    return ans;
}

void Init() {
    for (int i=2; i<= MaxN; i++) {
        cntsqr[i] = cntsqr[i-1];
        cntprime[i] = cntprime[i-1];
        ll tmp = CntDiv(i);
        if ((tmp > 2) && (!Sieve[tmp]))
            cntsqr[i]++;
        if (!Sieve[i])
            cntprime[i]++;
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        long long a,b, tmpa, tmpb;
        cin >> a >> b;
        tmpa = sqrt(a-1LL)+1LL;
        tmpb = sqrt(b);
        int ans = 0;
        if ((a <= 1000000) && (b <= 1000000))
            ans = (cntprime[b] - cntprime[a - 1]);
        ans += (cntsqr[tmpb] - cntsqr[tmpa - 1]);
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CPRIME.INP", "r", stdin);
    freopen("CPRIME.OUT", "w", stdout);
    MakeSieve();
    MakeD();
    Init();
    cin >> t;
    Solve();
    return 0;
}
