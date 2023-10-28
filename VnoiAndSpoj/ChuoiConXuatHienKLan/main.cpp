#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll Base1 = 29, Mod1 = 1e9 + 7, Base2 = 31, Mod2 = 908654317;
int n, k;
ll PowOfB1[MaxN+5], PowOfB2[MaxN+5];
map<pii, int> cnt;
string s;
vector<ll> h1, h2;

vector<ll> GenHash(string s, ll Base, ll Mod, ll powOfB[MaxN+5], bool MakePow = true) {
    int l = s.length();
    vector<ll> h(l+1, 0);
    powOfB[0] = 1;
    for (int i=1; i<=l; i++) {
        h[i] = (h[i-1]*Base + (s[i-1] - 'a' + 1LL))%Mod;
        if (MakePow)
            powOfB[i] = (powOfB[i-1]*Base)%Mod;
    }
    return h;
}

ll GetHash(const vector<ll>& h, ll Base, ll Mod, ll powOfB[MaxN+5], int l, int r) {
    return (h[r] - (h[l-1]*powOfB[r-l+1])%Mod + Mod)%Mod;
}

bool Check(int len) {
    cnt.clear();
    for (int i=1; i+len-1<=n; i++) {
        ll HashVal1 = GetHash(h1, Base1, Mod1, PowOfB1, i, i+len-1);
        ll HashVal2 = GetHash(h2, Base2, Mod2, PowOfB2, i, i+len-1);
        cnt[pii(HashVal1, HashVal2)]++;
        if (cnt[pii(HashVal1, HashVal2)] >= k)
            return true;
    }
    return false;
}

int Binsearch() {
    int lo = 0, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        if (Check(mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

int Solution() {
    h1 = GenHash(s, Base1, Mod1, PowOfB1, true);
    h2 = GenHash(s, Base2, Mod2, PowOfB2, true);
    return Binsearch();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> s;
    cout << Solution();
    return 0;
}
