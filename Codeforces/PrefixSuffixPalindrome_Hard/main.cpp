#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
string s;
int t, n;
ll PowB1[MaxN+1], PowB2[MaxN+1];
vector<ll> h1, h2, revh1, revh2;
const ll Base1 = 37, Mod1 = 908654317, Base2 = 53, Mod2 = 1e9 + 87;

void PolyHash(vector<ll>& h, const string& s, int len, ll Mod, ll Base, ll PowB[], bool MakeB) {
    h.assign(len + 1, 0);
    PowB[0] = 1;
    for (int i=1; i<=len; i++) {
        h[i] = ((h[i-1]*Base)%Mod + (s[i] - 'a' + 1LL))%Mod;
        if (MakeB)
            PowB[i] = (PowB[i-1]*Base)%Mod;
    }
}

ll GetHash(const vector<ll>& h, ll Mod, ll PowB[], int l, int r) {
    return (h[r] - (h[l-1]*PowB[r-l+1])%Mod + Mod)%Mod;
}

void SolveTestCase() {
    n = s.length();
    s = ' ' + s;
    PolyHash(h1, s, n, Mod1, Base1, PowB1, true);
    PolyHash(h2, s, n, Mod2, Base2, PowB2, true);
    reverse(s.begin(), s.end());
    s = ' ' + s;
    PolyHash(revh1, s, n, Mod1, Base1, PowB1, true);
    PolyHash(revh2, s, n, Mod2, Base2, PowB2, true);
    reverse(s.begin(), s.end());
    int k = 0;
    while ((s[k+1] == s[n - k]) && (k +1 < n - k))
        k++;
    int Pref = 0;
    for (int id = k+1; id<=n-k; id++) {
        if ((GetHash(h1, Mod1, PowB1, k+1, id) == GetHash(revh1, Mod1, PowB1, n - id + 1, n - k))
        && (GetHash(h2, Mod2, PowB2, k+1, id) == GetHash(revh2, Mod2, PowB2, n - id + 1, n - k)))
            Pref = max(Pref, id - k);
    }
    int Suf = 0;
    for (int id = k+1; id <= n-k; id++) {
        if ((GetHash(h1, Mod1, PowB1, id, n - k) == GetHash(revh1, Mod1, PowB1, k + 1, n - id + 1))
        && (GetHash(h2, Mod2, PowB2, id, n - k) == GetHash(revh2, Mod2, PowB2, k + 1, n - id + 1)))
            Suf = max(Suf, n - k - id + 1);
    }
    string ans = "";
    for (int i=1; i<=k; i++)
        ans.push_back(s[i]);
    if (Pref > Suf)
        for (int i=k+1; i<=k+Pref; i++)
            ans.push_back(s[i]);
    else
        for (int i=n-k-Suf+1; i<=n-k; i++)
            ans.push_back(s[i]);
    for (int i=n-k+1; i<=n; i++)
        ans.push_back(s[i]);
    cout << ans << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
        SolveTestCase();
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
