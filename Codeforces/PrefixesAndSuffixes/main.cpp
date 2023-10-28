#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100010
using namespace std;
typedef long long ll;
string s;
vector<ll> h;
int n, cntlen[MaxN+1];
bool IsSuf[MaxN+1];
ll PowB[MaxN+1];
const ll Base = 257, Mod = 1e9 + 87;

void Hash(vector<ll>& h, const string& s, int len, bool MakePow) {
    h.assign(len+1, 0);
    PowB[0] = 1;
    for (int i=1; i<=len; i++) {
        h[i] = ((h[i-1]*Base) + s[i])%Mod;
        if (MakePow)
            PowB[i] = (PowB[i-1] * Base)%Mod;
    }
}

ll GetHash(vector<ll>& h, int l, int r) {
    return ((h[r] - (h[l-1]*PowB[r - l + 1])%Mod + Mod)%Mod);
}

int BinsearchLen(vector<ll>& h, int id) {
    int lo = 0, hi = n - id + 1, ans = 0;
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        if (h[mid] == GetHash(h, id, id + mid - 1)) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

void Solve() {
    n = s.length();
    s = ' ' + s;
    Hash(h, s, n, true);
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        int MatchLen = BinsearchLen(h, i);
        if ((i + MatchLen - 1 == n) && (!IsSuf[MatchLen])) {
            IsSuf[MatchLen] = true;
            cnt++;
        }
        if (MatchLen != 0) {
            cntlen[1]++;
            cntlen[MatchLen+1]--;
        }
    }
    cout << cnt << '\n';
    for (int i=1; i<=n; i++) {
        cntlen[i] += cntlen[i-1];
        if (IsSuf[i])
            cout << i << ' ' << cntlen[i] << '\n';
    }
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
