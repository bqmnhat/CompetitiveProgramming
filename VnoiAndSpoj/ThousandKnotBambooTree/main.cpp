#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int t;
ll dp[MaxN+1][MaxN+1];
string s;

bool CmpStr(string s1, string s2) {
    while (s1.length() < s2.length())
        s1.push_back(char(90));
    while (s2.length() < s1.length())
        s2.push_back(char(90));
    return (s1 < s2);
}

ll Solution(string s) {
    int n = s.length();
    if (n == 1)
        return 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            dp[i][j] = 0;
    for (int i=0; i<n; i++)
        dp[0][i] = 1;
    for (int i=2; i<n; i++) {
        string tmp = "";
        for (int j=i; j<n; j++) {
            tmp += s[j];
            string tmp2 = "";
            for (int x = i-1; x>=0; x--) {
                tmp2 = s[x] + tmp2;
                if (CmpStr(tmp2, tmp))
                    dp[i][j] = (dp[i][j] + dp[x][i-1])%Mod;
            }
        }
    }
    ll ans = 0;
    for (int i=0; i<n; i++)
        ans = (ans + dp[i][n-1])%Mod;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
        cout << Solution(s) << '\n';
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
