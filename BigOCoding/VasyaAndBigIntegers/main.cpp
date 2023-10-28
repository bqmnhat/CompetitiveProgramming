#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int n;
string a, l, r;
vector<int> zL, zR;
ll dp[MaxN+1], sufSum[MaxN+1];
ll const Mod = 998244353;

vector<int> MakeZFunction(string s) {
    int n = s.length(), l = 0, r = 0;
    vector<int> z(n);
    z[0] = n;
    for (int i=1; i<n; i++) {
        if (i <= r)
            z[i] = min(z[i-l], r-i+1);
        while ((i + z[i] < n) && (s[i+z[i]] == s[z[i]]))
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int CmpStr(const vector<int>& z, string& s, int id) {
    int len = s.length();
    if (n - id < len)
        return 1;
    int x = z[len + id + 1];
    if (x == len)
        return 0;
    if (a[id + x] < s[x])
        return 1;
    return -1;
}

ll Solution() {
    n = a.length();
    dp[n] = 1;
    sufSum[n] = 1;
    zL = MakeZFunction(l + '#' + a);
    zR = MakeZFunction(r + '#' + a);
    for (int i=n-1; i >= 0; i--) {
        if (a[i] == '0') {
            if (l == "0")
                dp[i] = dp[i+1];
            else
                dp[i] = 0;
            sufSum[i] = (sufSum[i+1] + dp[i])%Mod;
            continue;
        }
        int L = i + l.length();
        if (CmpStr(zL, l, i) == 1)
            L++;
        int R = i + r.length();
        if (CmpStr(zR, r, i) == -1)
            R--;
        ll curVal = 0;
        if ((L <= R) && (L <= n)) {
            R = min(R, n);
            if (R == n)
                curVal = sufSum[L]%Mod;
            else
                curVal = (sufSum[L] - sufSum[R+1] + Mod)%Mod;
        }
        dp[i] = curVal;
        sufSum[i] = (sufSum[i+1] + dp[i])%Mod;
    }
    return dp[0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> l >> r;
    cout << Solution();
    return 0;
}
