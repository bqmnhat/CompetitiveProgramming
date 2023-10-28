#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
#define MaxY 100
using namespace std;
typedef long long ll;
int t, n, m, x, y;
ll PowB[MaxN+1];
vector<ll> hPat;
vector<vector<ll>> hRow;
const ll Mod = 1e9 + 7, Base = 31;
vector<string> s, pattern;

void ReadData() {
    string stmp;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> stmp;
        stmp = ' ' + stmp;
        s.push_back(stmp);
    }
    cin >> x >> y;
    for (int i=0; i<x; i++) {
        cin >> stmp;
        stmp = ' ' + stmp;
        pattern.push_back(stmp);
    }
}

void MakePowB() {
    PowB[0] = 1;
    for (int i=1; i<=MaxN; i++)
        PowB[i] = (PowB[i-1]*Base)%Mod;
}

ll GetHashVal(const vector<ll>& h, int l, int r) {
    return (h[r] - (h[l-1]*PowB[r-l+1])%Mod + Mod)%Mod;
}

ll OneTimeHash(string s) {
    int n = s.length();
    ll ans = 0;
    for (int i=1; i<n; i++)
        ans = ((ans * Base) + (s[i] - 'a' + 1LL))%Mod;
    return ans;
}

vector<ll> GenHash(string s) {
    int n = s.length();
    vector<ll> h(n, 0);
    ll tmp;
    for (int i=1; i<n; i++) {
        h[i] = ((h[i-1] * Base) + (s[i] - 'a' + 1LL))%Mod;
        tmp = h[i];
    }
    return h;
}

vector<ll> MakeZFunction(const vector<ll>& a) {
    int n = a.size();
    vector<ll> z(n+1, 0);
    z[0] = n;
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
        if (i <= r)
            z[i] = min(z[i-l], 1LL*(r-i+1));
        while ((i + z[i] < n) && (a[i+z[i]] == a[z[i]]))
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int Matching(const vector<ll>& board, const vector<ll>& pat) {
    int patlen = pat.size();
    vector<ll> tmp = pat;
    tmp.push_back(1e15);
    for (auto x: board)
        tmp.push_back(x);
    vector<ll> z = MakeZFunction(tmp);
    int tmplen = tmp.size(), boardlen = board.size(), ans = 0;
    for (int i=patlen+1; i<tmplen; i++)
        if (z[i] == patlen)
            ans++;
    return ans;
}

int Solution() {
    hPat.clear();
    hRow.clear();
    for (int i=0; i<x; i++) {
        ll tmph = OneTimeHash(pattern[i]);
        hPat.push_back(tmph);
    }
    for (int i=0; i<n; i++) {
        vector<ll> tmph = GenHash(s[i]);
        hRow.push_back(tmph);
    }
    int ans = 0;
    for (int j=1; j<=m; j++) {
        vector<ll> SubGridHashVals;
        SubGridHashVals.clear();
        for (int i=0; i<n; i++) {
            ll tmp = GetHashVal(hRow[i], j, j+y-1);
            SubGridHashVals.push_back(tmp);
        }
        ans += Matching(SubGridHashVals, hPat);
    }
    return ans;
}

void Solve() {
    MakePowB();
    for (int i=1; i<=t; i++) {
        s.clear();
        pattern.clear();
        ReadData();
        cout << Solution() << '\n';
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
