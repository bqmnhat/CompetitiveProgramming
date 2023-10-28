#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
const ll Mod = 1e8;
int T;
string s, t, TrimmedT;
unordered_set<ll> Exist;

string TrimU(string& s, int begpos, int& cntU) {
    string ans = "";
    int l = s.length();
    cntU = 0;
    for (int i = begpos; i<l; i++) {
        if (s[i] != 'U')
            ans.push_back(s[i]);
        else
            cntU++;
    }
    return ans;
}

ll NumOfSubseq(string& s) {
    ll dp[MaxN+5], last[257];
    memset(dp, 0, sizeof(dp));
    memset(last, -1, sizeof(last));
    int l = s.length();
    dp[0] = 1;
    for (int i=1; i<=l; i++) {
        dp[i] = (2*dp[i-1])%Mod;
        if (last[s[i-1]] != -1)
            dp[i] = (dp[i] - dp[last[s[i-1]]] + Mod)%Mod;
        last[s[i-1]] = (i-1);
    }
    return dp[l];
}

ll NxtNode(ll Mask, ll CurNode) {
    for (ll i=0; i<t.length(); i++) {
        if (Mask&(1LL << i)) {
            if (t[i] == 'L')
            CurNode = CurNode*2 + 1LL;
            else if (t[i] == 'R')
                CurNode = CurNode*2 + 2;
            else
                CurNode = ll((CurNode-1LL)/2);
        }
    }
    return CurNode;
}

ll SolutionLen50() {
    ll CurNode = 0;
    Exist.clear();
    for (int i=1; i<s.length(); i++) {
        if (s[i] == 'L')
            CurNode = CurNode*2 + 1LL;
        else if (s[i] == 'R')
            CurNode = CurNode*2 + 2;
        else
            CurNode = ll((CurNode-1LL)/2);
    }
    t.erase(t.begin(), t.begin()+1);
    int tl = t.length();
    for (ll i=0; i<(1 << tl); i++) {
        ll tmp = NxtNode(i, CurNode);
        if (Exist.find(tmp) == Exist.end())
            Exist.insert(tmp);
    }
    return (Exist.size());
}

ll Solution50() {
    /*ll CurHeight = 0;
    int ls = s.length();
    for (int i=1; i<ls; i++) {
        if (s[i] == 'U')
            CurHeight = max(0LL, CurHeight - 1LL);
        else
            CurHeight++;
    }
    int i = 1, lt = t.length();
    ll ans = 0;
    while ((i < lt) && (t[i] == 'U')) {
        CurHeight--;
        if (CurHeight != 0)
            ans = (ans + 1LL)%Mod;
        i++;
    }*/
    int cntU;
    ll ans = 0;
    TrimmedT = TrimU(t, 1, cntU);
    ans = (ans + NumOfSubseq(TrimmedT))%Mod;
    return ans;
}

void Solve() {
    for (int i=1; i<=T; i++) {
        cin >> s >> t;
        if (s.length() + t.length() <= 55)
            cout << SolutionLen50() << '\n';
        else
            cout << Solution50() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("BTREE.INP", "r", stdin);
    //freopen("BTREE.OUT", "w", stdout);
    cin >> T;
    Solve();
    return 0;
}
