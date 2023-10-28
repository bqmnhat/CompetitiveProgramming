#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500005
#define MaxC 26
using namespace std;
typedef long long ll;
ll f[MaxC+1][MaxN+1], fAndJSuf[MaxC+1][MaxN+1], fSuf[MaxC+1][MaxN+1];
string s;
int t, n;
const ll Mod = 1e9 + 7;

void PreCalculation() {
    n = s.length();
    s = ' ' + s;
    memset(f, 0, sizeof(f));
    memset(fAndJSuf, 0, sizeof(fAndJSuf));
    memset(fSuf, 0, sizeof(fSuf));
    for (int i=1; i<=n; i++)
        f[s[i] - 'a' + 1][i]++;
    for (int c=1; c<=MaxC; c++)
        for (int i=1; i<=n; i++)
            f[c][i] = (f[c][i] + f[c][i-1])%Mod;
    for (int c=1; c<=MaxC; c++) {
        for (int i=n; i>=1; i--) {
            fAndJSuf[c][i] = (fAndJSuf[c][i+1] + (f[c][i]*1LL*i)%Mod)%Mod;
            fSuf[c][i] = (f[c][i] + fSuf[c][i+1])%Mod;
        }
    }
}

void Solve() {
    for (int te = 1; te <= t; te++) {
        cin >> s;
        PreCalculation();
        ll ans = 0;
        for (int c=1; c<=MaxC; c++) {
            for (int i=1; i<=n; i++) {
                ll NumOfFreq = (1LL*(n + i)*1LL*(n-i+1LL))/2;
                ans = (ans + (1LL*c*(fAndJSuf[c][i] - (1LL*(i-1LL)*1LL*fSuf[c][i])%Mod - (NumOfFreq*f[c][i-1])%Mod + ((n-i+1LL)*1LL*(i-1LL)*1LL*(f[c][i-1]))%Mod + Mod*2)%Mod))%Mod;
            }
        }
        cout << ans << '\n';
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
