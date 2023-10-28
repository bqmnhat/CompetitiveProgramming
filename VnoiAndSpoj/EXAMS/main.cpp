#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n;
ll a[MaxN+1], pref[MaxN+1];
const ll Mod = 1e9+7;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=n; i++)
        ans = (ans + (1LL * ((pref[i-1]%Mod) * (a[i]%Mod))%Mod * ((pref[n] - pref[i])%Mod))%Mod)%Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
