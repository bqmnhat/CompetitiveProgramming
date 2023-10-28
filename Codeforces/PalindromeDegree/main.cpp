#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000000
using namespace std;
typedef long long ll;
string s;
ll Base = 31, Mod = 1e9 + 11, powOfB[MaxN+1], dp[MaxN+1];

vector<ll> GenHash(string s, bool MakePow) {
    int l = s.length();
    vector<ll> h(l+1, 0);
    powOfB[0] = 1;
    for (int i=1; i<=l; i++) {
        h[i] = (h[i-1]*Base + s[i-1])%Mod;
        if (MakePow)
            powOfB[i] = (powOfB[i-1]*Base)%Mod;
    }
    return h;
}

ll GetHash(const vector<ll>& h, int l, int r) {
    return (h[r] - (h[l-1]*powOfB[r-l+1])%Mod + Mod)%Mod;
}

ll Solution() {
    ll ans = 0;
    int l = s.length();
    vector<ll> h, h_rev;
    h = GenHash(s, false);
    reverse(s.begin(), s.end());
    h_rev = GenHash(s, true);
    for (int i=1; i<=l; i++) {
        if (h[i] == GetHash(h_rev, l-i+1, l))
            dp[i] = dp[i/2] + 1;
        ans += dp[i];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    cout << Solution();
    return 0;
}
