#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> BigInt;
int k;
BigInt dp[2003];

BigInt operator + (BigInt a, BigInt b) {
    BigInt ans;
    int i = 0, j = 0, tmp = 0;
    while ((i < a.size()) || (j < b.size())) {
        if (i < a.size()) {
            tmp += a[i];
            i++;
        }
        if (j < b.size()) {
            tmp += b[j];
            j++;
        }
        ans.push_back(tmp%10);
        tmp = tmp/10;
    }
    if (tmp > 0)
        ans.push_back(tmp);
    return ans;
}

void SolveEquations() {
    dp[3] = {6};
    dp[4] = {0,1};
    for (int i=5; i<=k+2; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
}

void PrintAns(BigInt x) {
    for (int i=x.size()-1; i>=0; i--)
        cout << x[i];
}

int main()
{
    freopen("BOOLSYS.INP", "r", stdin);
    freopen("BOOLSYS.OUT", "w", stdout);
    cin >> k;
    SolveEquations();
    PrintAns(dp[k+2]);
    return 0;
}
