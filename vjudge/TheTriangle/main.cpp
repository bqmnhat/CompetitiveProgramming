#include <iostream>
#define MaxN 110
using namespace std;
int n, a[MaxN+1][MaxN+1], dp[MaxN+1][MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=i; j++)
            cin >> a[i][j];
}

int Solution() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            dp[i][j] += a[i][j];
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
        }
    }
    for (int i=1; i<=n; i++)
        ans = max(ans, dp[n][i]);
    return ans;
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
