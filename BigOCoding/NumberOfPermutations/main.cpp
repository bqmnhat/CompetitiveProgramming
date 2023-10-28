#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n;
ll cnt1[MaxN+1], cnt2[MaxN+1], fac[MaxN+1];
pii a[MaxN+1];
const ll Mod = 998244353;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].first >> a[i].second;
        cnt1[a[i].first]++;
        cnt2[a[i].second]++;
    }
}

void MakeFac() {
    fac[0] = fac[1] = 1;
    for (int i=2; i<=MaxN; i++)
        fac[i] = (fac[i-1]*i)%Mod;
}

ll Solution() {
    ll ans = fac[n], cnt1Prod = 1, cnt2Prod = 1;
    for (int i=1; i<=MaxN; i++) {
        cnt1Prod = (cnt1Prod*fac[cnt1[i]])%Mod;
        cnt2Prod = (cnt2Prod*fac[cnt2[i]])%Mod;
    }
    sort(a+1, a+1+n);
    ll PairProd = 1;
    for (int i=2; i<=n; i++) {
        if ((a[i].first < a[i-1].first) || (a[i].second < a[i-1].second)) {
            PairProd = 0;
            break;
        }
    }
    int cnt = 1;
    for (int i=2; i<=n; i++) {
        if ((a[i].first == a[i-1].first) && (a[i].second == a[i-1].second))
            cnt++;
        else {
            PairProd = (PairProd*fac[cnt])%Mod;
            cnt = 1;
        }
    }
    if (cnt > 1)
        PairProd = (PairProd*fac[cnt])%Mod;
    ans = (ans - cnt1Prod - cnt2Prod + PairProd + Mod*Mod)%Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeFac();
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
