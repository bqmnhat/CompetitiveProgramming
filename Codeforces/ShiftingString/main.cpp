#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200
using namespace std;
typedef long long ll;
int t, n, p[MaxN+1];
string s;
bool vis[MaxN+1];

void ReadData() {
    for (int i=0; i<n; i++) {
        cin >> p[i];
        p[i]--;
    }
}

vector<int> MakeZFunction(string s, int len) {
    vector<int> z(len+1, 0);
    int l = 0, r = 0;
    for (int i=1; i<len; i++) {
        if (i <= r)
            z[i] = min(z[i-l], r-i+1);
        while ((i + z[i] < len) && (s[i+z[i]] == s[z[i]]))
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int CycleLen(string s, int len) {
    string tmps = s + '#' + s + s;
    int slen = tmps.length();
    vector<int> z = MakeZFunction(tmps, slen);
    for (int i=len+2; i<slen; i++)
        if (z[i] == len)
            return i-len-1;
    return len;
}

ll LCM(ll a, ll b) {
    ll GCD = __gcd(a, b);
    ll ans = (a*b)/GCD;
    return ans;
}

ll Solution() {
    int cnt = 0, i = 0;
    ll ans = 1;
    memset(vis, false, sizeof(vis));
    while (cnt < n) {
        while (vis[i])
            i++;
        string tmp = "";
        while (!vis[i]) {
            tmp = tmp + s[i];
            vis[i] = true;
            i = p[i];
            cnt++;
        }
        ll cl = CycleLen(tmp, tmp.length());
        ans = LCM(ans, cl);
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> s;
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
