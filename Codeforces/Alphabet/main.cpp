#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> LIS;
int dp[51];

int FindLIS(string s) {
    int n = s.length();
    for (int i=0; i<n; i++)
        dp[i] = 1;
    for (int i=0; i<n; i++) {
        int j = lower_bound(LIS.begin(), LIS.end(), s[i]) - LIS.begin();
        dp[i] = j + 1;
        if (j == LIS.size())
            LIS.push_back(s[i]);
        else
            LIS[j] = s[i];
    }
    return LIS.size();
}

int Solution() {
    return (26 - FindLIS(s));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    cout << Solution();
    return 0;
}
