#include <iostream>
#include <bits/stdc++.h>
#define MaxN 11
#define MaxModVal 2048
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 9;
ll dp[MaxN+5][MaxModVal+5], Pow10[MaxN+5];
vector<ll> n;

void ReadData() {
    string s;
    cin >> s;
    int l = s.length();
    n.push_back(16);
    for (int i=l-1; i>=0; i--) {
        if (s[i] == '?')
            n.push_back(-1);
        else
            n.push_back(s[i] - '0');
    }
}

void MakePow10() {
    Pow10[0] = 1;
    for (int i=1; i<=MaxN; i++)
        Pow10[i] = (Pow10[i-1]*10)%MaxModVal;
}

ll Solution() {
    dp[0][0] = 1;
    int l = n.size()-1;
    for (int i=1; i<=min(l, 11); i++) {
        ll PreModVal;
        for (ll j=0; j<MaxModVal; j++) {
            if (n[i] == -1) {
                for (int tmp=0; tmp<=9; tmp++) {
                    PreModVal = (j - (tmp*Pow10[i-1])%MaxModVal + MaxModVal)%MaxModVal;
                    dp[i][j] = (dp[i][j] + dp[i-1][PreModVal])%Mod;
                }
            }
            else {
                PreModVal = (j - (n[i]*Pow10[i-1])%MaxModVal + MaxModVal)%MaxModVal;
                dp[i][j] = dp[i-1][PreModVal];
            }
        }
    }
    ll ans = dp[min(l, 11)][0];
    for (int i=12; i<=l; i++)
        if (n[i] == -1)
            ans = (ans*10)%Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ReadData();
    MakePow10();
    cout << Solution();
    return 0;
}
