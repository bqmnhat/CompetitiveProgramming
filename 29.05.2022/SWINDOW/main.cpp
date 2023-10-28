#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000000
using namespace std;
typedef long long ll;
string t, p;
int k, n, z[MaxN+1], plen, tlen, cnt[MaxN+1], lcnt = 0;

void MakeZFunction(string s) {
    z[0] = n;
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
        if (i <= r)
            z[i] = min(z[i-l], r-i+1);
        while ((i + z[i] < n) && (s[z[i]] == s[i + z[i]]))
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

int CntSw(int lo, int hi) {
    return max(0, ((hi - k + 1) - lo + 1)); // sliding window low and high illegally exist or too small => max(0, Val)
}

ll Solution() {
    string tmp = p + '#' + t;
    n = tmp.length();
    plen = p.length();
    tlen = t.length();
    MakeZFunction(tmp);
    ll ans = 0;
    int Prelo = 0, Prehi = 0, lo, hi;
    for (int i=plen+1; i<n; i++) {
        if (z[i] == plen) {
            lo = max(plen+1, i + plen - k);
            hi = min(n-1, i + k - 1);
            ans += (CntSw(lo, hi) - CntSw(lo, Prehi));
            Prelo = lo;
            Prehi = hi;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SWINDOW.INP", "r", stdin);
    freopen("SWINDOW.OUT", "w", stdout);
    getline(cin, t);
    cin >> p >> k;
    cout << Solution();
    return 0;
}
