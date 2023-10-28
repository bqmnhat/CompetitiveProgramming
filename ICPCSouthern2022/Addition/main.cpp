#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
string s1, s2, s3;
vector<int> Num1, Num2, Res;
int dp[MaxN+5][2], n;

void ReadData() {
    cin >> s1 >> s2 >> s3;
    Num1.clear();
    Num2.clear();
    Res.clear();
    for (int i=0; i<n; i++) {
        int a;
        a = s1[i] - '0';
        Num1.push_back(a);
    }
    Num1.push_back(0);
    for (int i=0; i<n; i++) {
        int a;
        a = s2[i] - '0';
        Num2.push_back(a);
    }
    Num2.push_back(0);
    for (int i=0; i<n; i++) {
        int a;
        a = s3[i] - '0';
        Res.push_back(a);
    }
    Res.push_back(0);
}

int Solution() {
    memset(dp, 0, sizeof(dp));
    for (int i=n-1; i>=0; i--) {
        if (((Num1[i] + Num2[i])%10) == Res[i])
            dp[i][(Num1[i] + Num2[i])/10] = 1;
        for (int j=i+1; j<n; j++) {
            for (int r = 0; r<=1; r++) {
                int NxtR = (Num1[i] + Num2[i] + r)/10;
                if (((Num1[i] + Num2[i] + r)%10) == Res[i])
                    dp[i][NxtR] = max(dp[i][NxtR], dp[j][r] + 1);
            }
        }
    }
    int tmp = 0;
    for (int i=0; i<n; i++)
        tmp = max(tmp, dp[i][0]);
    return n - tmp;
}

void Solve() {
    while ((cin >> n) && (n != 0)) {
        ReadData();
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
