#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, arr[101], c[101][2001], dp[101][2001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> arr[i];
}

int Solution() {
    int sum = 0, ans = 0;
    for (int i=1; i<=n; i++)
        sum += arr[i];
    for (int i=0; i<=n; i++)
        dp[i][0] = 1;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=sum; j++)
        {
            if (arr[i] <= j) {
                if (c[i-1][j] <= m) {
                    dp[i][j] += dp[i-1][j];
                    c[i][j] = c[i-1][j];
                }
                if (c[i-1][j-arr[i]] < m) {
                    dp[i][j] += dp[i-1][j-arr[i]];
                    c[i][j] = c[i-1][j-arr[i]]+1;
                }
            }
            else if (c[i-1][j] <= m) {
                dp[i][j] += dp[i-1][j];
                c[i][j] = c[i-1][j];
            }
        }
    }
}

int main() {
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
