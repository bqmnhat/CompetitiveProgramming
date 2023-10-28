#pragma GCC optimize("Ofast")
#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxVal 10000
using namespace std;
typedef long long ll;
int n;
ll x[MaxN+5], d[MaxVal+5], freqPrime[MaxVal+5], MaxXi = 0;
vector<ll> AllMu, Prime;

void MakeSieve() {
    for (int i=2; i*i<=MaxVal; i++)
        if (d[i] == 0)
            for(int j=i; i*j<=MaxVal; j++)
                d[i*j] = i;
    for (int i=2; i<=MaxVal; i++)
        if (d[i] == 0)
            Prime.push_back(i);
}

ll GetFactor(ll n, ll p) {
    ll ans = 0;
    while (n%p == 0) {
        ans++;
        n /= p;
    }
    return ans;
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> x[i];
        MaxXi = max(MaxXi, x[i]);
    }
}

//int CntPrime() {
//    int cnt = 0;
//    for (int i=2; i<=MaxVal; i++) {
//        if (d[i] == 0)
//            cnt++;
//    }
//    return cnt;
//}

ll FastPow(ll base, ll e) {
    ll ans = 1;
    while (e > 0) {
        if (e&1LL)
            ans = ans*base;
        base = base*base;
        e >>= 1LL;
    }
    return ans;
}

void FindFreqPrime() {
    for (ll p: Prime)
        for (int i=1; i<=n; i++)
            freqPrime[p] += ((x[i]%p) == 0);
}

ll FindMed(ll& MinMove) {
    ll res = 1;
    MinMove = 0;
    FindFreqPrime();
    for (ll p: Prime) {
        if (p > MaxXi)
            break;
        AllMu.clear();
        if (p > 105) {
            int cntOne = freqPrime[p];
            int cntZero = n - cntOne;
            int Med = (n >> 1);
            if (n&1)
                Med++;
            if (cntZero < Med) {
                res *= p;
                MinMove += cntZero;
            }
            else
                MinMove += cntOne;
            continue;
        }
        for (int i=1; i<=n; i++)
            AllMu.push_back(GetFactor(x[i], p));
        sort(AllMu.begin(), AllMu.end());
        int Med = (AllMu.size() >> 1);
        if (AllMu.size()&1)
            Med++;
        //cout << "Prime: " << p << " Mu: " << AllMu[Med-1] << '\n';
        res = res * FastPow(p, AllMu[Med-1]);
        for (ll tmp: AllMu)
            MinMove += abs(tmp - AllMu[Med-1]);
    }
    return res;
}

void Solve() {
    ll MinMove = 0;
    ll res = FindMed(MinMove);
    cout << MinMove << ' ' << res;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    MakeSieve();
    ReadData();
    Solve();
    return 0;
}
