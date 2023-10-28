#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int t;
ll a, b;
map<ll, int> Fac;

/*void MakeSieve() {
    for (int i=2; i*i<= MaxN; i++)
        if (Sieve[i] == 0)
            for (int j=i; i*j <= MaxN; j++)
                Sieve[i*j] = i;
}*/

void SingleFactorise(ll x) { //Sorry anh em khum biet cach phan tich thua so nguyen to a <= 1e9 :<<<
    ll tmp = sqrt(x);
    int i = 2;
    while ((x > 1) && (i <= tmp)) {
        while (x%i == 0) {
            Fac[i]++;
            x/=i;
        }
        i++;
    }
    if (x > 1)
        Fac[x]++;
}

ll Factorise2(ll a, ll b) {
    SingleFactorise(a);
    SingleFactorise(b);
    ll ans = 1;
    for (auto i=Fac.begin(); i!=Fac.end(); i++)
        ans = ans*((2*(*i).second)+1LL);
    return ans;
}

ll Solution() {
    Fac.clear();
    ll CntDiv = Factorise2(a, b);
    return CntDiv;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> a >> b;
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("EQUATION.INP", "r", stdin);
    freopen("EQUATION.OUT", "w", stdout);
    cin >> t;
    Solve();
    return 0;
}
