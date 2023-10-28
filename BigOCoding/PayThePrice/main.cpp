#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string Inp;
int n, l1, l2;
ll dp[301][1001];

void InitDp() {
    for (int i = 0; i<=300; i++)
        for (int j=0; j<=1000; j++)
            dp[i][j] = 0;
    dp[0][0] = 1;
}

void CalDp() {
    for (int i=1; i<=300; i++)
        for (int j=i; j<=300; j++)
            for (int k=1; k<=300; k++)
                dp[j][k] += dp[j-i][k-1];
}

int StringToInt(string s) {
    int ans = 0, l = s.length();
    for (int i=0; i<l; i++)
        ans = ans*10 + int(s[i] - '0');
    return ans;
}

ll Solution() {
    l1 = l2 = 0;
    string tmp = "";
    Inp = Inp + ' ';
    int ls = Inp.length(), cnt = 0;;
    for (int i=0; i<ls; i++) {
        if (Inp[i] != ' ')
            tmp = tmp + Inp[i];
        else {
            cnt++;
            if (cnt == 1)
                n = StringToInt(tmp);
            else if (cnt == 2)
                l1 = StringToInt(tmp);
            else if (cnt == 3)
                l2 = StringToInt(tmp);
            tmp = "";
        }
    }
    ll ans = 0;
    if (cnt == 1)
        for (int i=0; i<=300; i++)
            ans += dp[n][i];
    else if (cnt == 2)
        for (int i=0; i<=l1 && i<=300; i++)
            ans += dp[n][i];
    else
        for (int i=l1; i<=l2 && i<=300; i++)
            ans += dp[n][i];
    return ans;
}

void Solve() {
    InitDp();
    CalDp();
    while (getline(cin, Inp)) {
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
