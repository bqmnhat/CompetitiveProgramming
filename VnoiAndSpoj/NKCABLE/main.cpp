#include <iostream>
#include <bits/stdc++.h>
#define MaxN 25000
using namespace std;
typedef long long ll;
const ll INF = 1e13;
int n;
ll a[MaxN+5], pref[MaxN+5], dp[MaxN+5];

void ReadData() {
    for (int i=1; i<n; i++)
        cin >> a[i];
}

void CalPref() {
    for (int i=1; i<n; i++)
        pref[i] = pref[i-1] + a[i];
}

ll Solution() {
    for (int i=1; i<=n; i++) {
        dp[i] = INF;
        for (int j=i-1; j>=1; j--)
            dp[i] = min(dp[i], dp[j-1] + pref[i-1] - pref[j-1]);
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    CalPref();
    cout << Solution();
    return 0;
}
