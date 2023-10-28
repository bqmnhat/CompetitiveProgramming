#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
typedef long long ll;
typedef vector<ll> BigNum;
int n;
BigNum dp[MaxN+1][2];

BigNum operator + (BigNum a, BigNum b) {
    BigNum ans;
    int i = 0, j = 0, r = 0;
    while ((i < a.size()) || (j < b.size())) {
        if (i < a.size())
            r += a[i++];
        if (j < b.size())
            r += b[j++];
        ans.push_back(r%10);
        r = r/10;
    }
    if (r > 0)
        ans.push_back(r);
    return ans;

}

void PrintBigNum(BigNum a) {
    int l = a.size();
    for (int i = l - 1; i>=0; i--)
        cout << a[i];
}

void Solve() {
    dp[1][0] = dp[1][1] = {1};
    for (int i=2; i<=n; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = dp[i-1][1] + dp[i-1][0];
    }
    BigNum Ans = dp[n][0] + dp[n][1];
    PrintBigNum(Ans);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Solve();
    return 0;
}
