#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
int n;
ll D[MaxN+1], dp[MaxN+1];
string s;

void ReadData() {
    cin >> s;
    s = ' ' + s;
    for (int i=1; i<=n; i++)
        cin >> D[i];
}

ll SameDigitsAns(int len) {
    for (int i=0; i<=len; i++)
        dp[i] = 0;
    ll ans = 0;
    for (int i=1; i<=len; i++)
        for (int j=1; j<=i; j++)
            dp[i] = max(dp[i], dp[i - j] + D[j]);
    return dp[len];
}

ll Solution(string s1) {
    if (s1.size() == 1)
        return 0;
    int PrevPos = 1, l = s1.length()-1;
    ll ans = 0;
    for (int i=2; i<=l+1; i++) {
        if ((i == l + 1) || ((i <= l) && (s1[i] != s1[i-1]))) {
            string tmp = " ";
            for (int j=1; j<PrevPos; j++)
                tmp += s1[i];
            for (int j=i; j<=l; j++)
                tmp += s1[j];
            ans = max(ans, SameDigitsAns(i - PrevPos) + Solution(tmp));
            PrevPos = i;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("XOADAY.INP", "r", stdin);
    //freopen("XOADAY.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution(s);
    return 0;
}
