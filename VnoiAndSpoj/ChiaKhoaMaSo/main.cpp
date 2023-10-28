#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50000
using namespace std;
typedef long long ll;
int t, n;
ll a[MaxN+1], k;
vector<ll> MulOfPrimesOfK;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Factorize(ll k, vector<ll>& f) {
    ll tmp = sqrt(k), i = 2;
    f.clear();
    while ((i <= tmp) && (k > 1)) {
        if (k%i == 0) {
            ll val = 1;
            while (k%i == 0) {
                val = val*i;
                k /= i;
            }
            f.push_back(val);
        }
        i++;
    }
    if ((k > 1) || (f.empty()))
        f.push_back(k);
}

bool Solution() {
    Factorize(k, MulOfPrimesOfK);
    vector<ll> X(MulOfPrimesOfK.size(), 0);
    for (int i=0; i<MulOfPrimesOfK.size(); i++) {
        //int tmp = MulOfPrimesOfK[i];
        for (int j=1; j<=n; j++)
            if (a[j]%MulOfPrimesOfK[i] == 0)
                X[i] = __gcd(X[i], a[j]);
    }
    for (ll x: X)
        if ((!x) || (k%x != 0))
            return false;
    return true;
}

void Solve() {
    for (int i=1; i<= t; i++) {
        cin >> n;
        ReadData();
        cin >> k;
        if (Solution())
            cout << "YES\n";
        else
            cout << "NO\n";
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
