#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
string s[MaxN+1];
int n, k;
ll Mod = 1e9 + 7;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> s[i];
}

string RevInterleaved(string a) {
    string tmp = a, tmp2, ans = "";
    reverse(a.begin(), a.end());
    tmp2 = a;
    int l = a.length();
    for (int i=0; i<l; i++) {
        ans.push_back(tmp[i]);
        ans.push_back(tmp2[i]);
    }
    return ans;
}

bool CmpStr(string a, string b) {
    return (a < b);
}

void MakeNewS() {
    for (int i=1; i<=n; i++)
        s[i] = RevInterleaved(s[i]);
    sort(s+1, s+1+n, CmpStr);
}

string SubStr(string a, int len) {
    string ans = "";
    int l = a.length();
    if (l < len)
        return ans;
    for (int i=0; i<l && i<=len-1; i++)
        ans.push_back(a[i]);
    return ans;
}

ll CntPairs(int k) {
    ll ans = 0, tmp = 1;
    for (int i=2; i<=n; i++) {
        string s1 = SubStr(s[i], 2*k), s2 = SubStr(s[i-1], 2*k);
        if ((s1 == s2) && (s1.length() >= 2*k) && (s2.length() >= 2*k))
            tmp++;
        else {
            ans = ((ans%Mod) + (((tmp*(tmp-1LL))/2)%Mod))%Mod;
            tmp = 1;
        }
    }
    ans = ((ans%Mod) + (((tmp*(tmp-1LL))/2)%Mod))%Mod;
    return ans;
}

ll Solution() {
    ll ans = CntPairs(k) - CntPairs(k+1);
    if (ans < 0)
        ans = ans + Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("GENEMAP.INP", "r", stdin);
    freopen("GENEMAP.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    MakeNewS();
    cout << Solution();
    return 0;
}
