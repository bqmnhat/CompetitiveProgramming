#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n;
string s;
ll dp[MaxN+1];
const ll Mod = 1e9 + 7;

bool CanInscribe(string s) {
    for (int i=1; i<n; i++)
        if ((s[i] == 'm') || (s[i] == 'w'))
            return false;
    return true;
}

ll Solution() {
    s = " " + s;
    n = s.length();
    dp[0] = dp[1] = 1;
    if (!CanInscribe(s))
        return 0;
    for (int i=2; i<n; i++) {
        if (((s[i] == 'n') && (s[i-1] == s[i])) || ((s[i] == 'u') && (s[i-1] == s[i])))
            dp[i] = (dp[i-1] + dp[i-2])%Mod;
        else
            dp[i] = dp[i-1];
    }
    return dp[n-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    cout << Solution();
    return 0;
}
