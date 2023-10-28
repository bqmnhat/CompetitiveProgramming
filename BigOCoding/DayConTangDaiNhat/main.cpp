#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, dp[30001];
ll a[30001];
vector<ll> LIS;

void ReadData() {
    for (int i = 1; i<=n; i++)
        cin >> a[i];
}

int Solution() {
    for (int i=1; i<=n; i++)
        dp[i] = 1;
    for (int i=1; i<=n; i++) {
        int j = lower_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
        dp[i] = j + 1;
        if (j == LIS.size()) {
            LIS.push_back(a[i]);
        }
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
    cout << Solution();
    return 0;
}
