#include <iostream>
#define MaxN 1000
using namespace std;
int n, a[MaxN+1], dp[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int Solution() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        dp[i] = 1;
        for (int j=1; j<i; j++)
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
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
