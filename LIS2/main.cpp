#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, a[MaxN+5], dp[MaxN+5];
vector<int> LIS;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int FindLIS() {
    LIS.push_back(a[1]);
    dp[1] = 1;
    for (int i=2; i<=n; i++) {
        int j = lower_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
        dp[i] = j + 1;
        if (j == LIS.size())
            LIS.push_back(a[i]);
        else
            LIS[j] = a[i];
    }
    return LIS.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << FindLIS();
    return 0;
}
