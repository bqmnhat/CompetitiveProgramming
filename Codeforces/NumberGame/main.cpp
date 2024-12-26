#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int t;
ll n;
map<ll, ll> mu;

void CntDiv(ll x) {
    mu.clear();
    ll i = 2, tmp = sqrt(x);
    while ((x > 1) && (i <= tmp)) {
        while ((x > 1) && (x%i == 0)) {
            mu[i]++;
            x/=i;
        }
        i++;
    }
    if (x > 1)
        mu[x]++;
}

void SolveTestCase() {
    if (n == 1) {
        cout << "FastestFinger" << '\n';
        return;
    }
    if ((n%2 == 1) || (n == 2)) {
        cout << "Ashishgup" << '\n';
        return;
    }
    bool Just2 = true;
    int cntOdd = 0;
    for (auto p: mu) {
        ll base = p.first, e = p.second;
        if (base != 2) {
            Just2 = false;
            cntOdd += e;
        }
    }
    if ((Just2) || ((!Just2) && (mu[2] == 1) && (cntOdd == 1)))
        cout << "FastestFinger" << '\n';
    else
        cout << "Ashishgup" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        CntDiv(n);
        SolveTestCase();
    }
    return 0;
}
