#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500
#define MaxVal 100000
using namespace std;
typedef long long ll;
int n;
ll a[MaxN+5], sum = 0;
bool dp[MaxN+5][MaxVal+5];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

void Init() {
    for (int i=0; i<=n; i++)
        dp[i][0] = true;
}

ll Solution() {
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=sum; j++) {
            dp[i][j] |= dp[i-1][j];
            if (j - a[i] >= 0)
                dp[i][j] |= dp[i-1][j-a[i]];
        }
    }
    ll ans = 0;
    for (int k=sum/2; k>=0; k--) {
        if (dp[n][k]) {
            ans = k;
            break;
        }
    }
    ans += ans - (sum-ans);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Init();
    cout << Solution();
    return 0;
}
