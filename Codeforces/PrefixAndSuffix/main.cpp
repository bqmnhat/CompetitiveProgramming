#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
string s;
int n, cnt[MaxN+1];
const ll Base = 31, Mod = 1e9 + 11;
ll PowOfB[MaxN+1];

vector<ll> GenHash(string s, bool MakePow) {
    vector<ll> h(n+1, 0);
    PowOfB[0] = 1;
    for (int i=1; i<=n; i++) {
        h[i] = ((h[i-1]*Base)%Mod + (s[i] - 'A' + 1))%Mod;
        if (MakePow)
            PowOfB[i] = (PowOfB[i-1]*Base)%Mod;
    }
    return h;
}

ll GetHash(const vector<ll>& h, int l, int r) {
    return (h[r] - (h[l-1]*PowOfB[r-l+1])%Mod + Mod)%Mod;
}

int BinSearchLen(const vector<ll>& h, int lo, int hi, int i) {
    int ans = 0, mid;
    while (lo <= hi) {
        mid = (lo + hi)/2;
        if (GetHash(h, 1, mid) == GetHash(h, i, i+mid-1)) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid-1;
    }
    return ans;
}

void Solve() {
    n = s.length();
    s = ' ' + s;
    vector<ll> h = GenHash(s, true);
    vector<int> ans;
    for (int i=1; i<=n; i++) {
        int MaxLen = BinSearchLen(h, 1, n-i+1, i); // Maximum length of substring start from i that equal to prefix of s
        if (MaxLen == n-i+1) // if Prefix == Suffix
            ans.push_back(MaxLen);
        cnt[MaxLen]++;
    }
    for (int i=n-1; i>=1; i--)
        cnt[i] += cnt[i+1];
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto len: ans)
        cout << len << ' ' << cnt[len] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    Solve();
    return 0;
}
