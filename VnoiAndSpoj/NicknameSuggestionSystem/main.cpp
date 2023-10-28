#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll Mod = 908654317, Base = 31;
int n, dp[MaxN+5], ans[MaxN+5];
ll PowOfB[MaxN+5];
unordered_map<ll, int> um;
vector<ll> HashVal[MaxN+5];
struct Str {
    ll len, HVal, id;
} s[MaxN+5];

vector<ll> GenHash(string s) {
    int n = s.length();
    vector<ll> h(n+1, 0);
    PowOfB[0] = 1;
    for (int i=1; i<=n; i++) {
        h[i] = ((h[i-1]*Base)%Mod + 1LL*(s[i-1] - 'a' + 1LL))%Mod;
        PowOfB[i] = (PowOfB[i-1]*Base)%Mod;
    }
    return h;
}

ll GetHash(const vector<ll>& h, int l, int r) {
    return (h[r] - (h[l-1]*PowOfB[r-l+1])%Mod + Mod)%Mod;
}

ll InsertHash(const vector<ll>& h, int pos, int len) {
    return ((((GetHash(h, 1, pos)*Base)%Mod + GetHash(h, pos, pos))%Mod * PowOfB[len - pos])%Mod + GetHash(h, pos+1, len))%Mod;
}

void ReadData() {
    string si;
    for (int i=1; i<=n; i++) {
        cin >> si;
        HashVal[i] = GenHash(si);
        s[i].HVal = HashVal[i][si.length()];
        s[i].len = si.length();
        s[i].id = i;
    }
}

bool CmpStrLen(Str a, Str b) {
    return (a.len > b.len);
}

/*bool CmpStrId(Str a, Str b) {
    return (a.id < b.id);
}*/

void Solve() {
    sort(s+1, s+1+n, CmpStrLen);
    for (int i=1; i<=n; i++)
        um[s[i].HVal] = i;
    for (int i=1; i<=n; i++)
        dp[i] = 1e9;
    dp[1] = 1;
    for (int i=2; i<=n; i++) {
        for (int j=0; j<s[i].len; j++) {
            ll NewHVal = InsertHash(HashVal[s[i].id], j+1, s[i].len);
            if (um.find(NewHVal) != um.end())
                dp[i] = min(dp[i], dp[um[NewHVal]]);
            else
                dp[i] = 0;
        }
        dp[i]++;
    }
    for (int i=1; i<=n; i++)
        ans[s[i].id] = dp[i];
    for (int i=1; i<=n; i++)
        cout << ans[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
