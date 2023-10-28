#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
typedef long long ll;
ll dp[MaxN+1];
string s;

int GetNum(int pos) {
    return (10*(s[pos] - '0')  + (s[pos+1] - '0'));
}

ll Solution() {
    int l = s.length();
    dp[l] = 1;
    for (int i=l-1; i>=0; i--) {
        if (s[i] == '0') {
            dp[i] = 0;
            continue;
        }
        dp[i] = dp[i+1];
        int tmp = GetNum(i);
        if ((i <= l-2) && (0 < tmp) && (tmp <= 26))
            dp[i] += dp[i+2];
    }
    return dp[0];
}

void Solve() {
    while ((cin >> s) && (s != "0"))
        cout << Solution() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
