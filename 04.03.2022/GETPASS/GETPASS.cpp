#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, pre[26], suf[26];
string s, t;

ll Solution() {
    ll Ans = 1LL*n*m;
    for (int i=1; i<n; i++)
        pre[int(s[i] - 'a')]++;
    for (int i=0; i<m-1; i++)
        suf[int(t[i] - 'a')]++;
    for (int i=0; i<26; i++)
        Ans = Ans - (1LL*pre[i]*suf[i]);
    return Ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("GETPASS.INP", "r", stdin);
    freopen("GETPASS.OUT", "w", stdout);
    cin >> s >> t;
    n = s.length();
    m = t.length();
    cout << Solution();
    return 0;
}
