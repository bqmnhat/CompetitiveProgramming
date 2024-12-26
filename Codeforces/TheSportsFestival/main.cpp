#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
typedef long long ll;
int n;
ll a[MaxN+5], dp[MaxN+5][MaxN+5];

void ReadData() {
    for (int i = 1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    sort(a + 1, a + 1 + n);
    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j++) {
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = a[j] - a[i] + min(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[1][n];
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
