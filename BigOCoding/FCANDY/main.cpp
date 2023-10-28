#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, c[101], k[101], dp[10000001], Prev[10000001];
ll MaxSum = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> k[i] >> c[i];
        MaxSum += (k[i] * c[i]);
    }
}

int Solution() {
    Prev[0] = 1;
    for (int i=1; i<=n; i++) {
        int a = k[i] * c[i];
        for (int j=0; 2*j <= MaxSum; j++) {
            if (Prev[j] > 0)
                dp[j] = 1;
            else
                dp[j] = 0;
            if (j - c[i] >= 0) {
                dp[j] += dp[j-c[i]];
                if ((j - a - c[i] >= 0) && (Prev[j-a-c[i]] > 0))
                    dp[j]--;
            }
        }
        for (int i=0; 2*i <= MaxSum; i++)
            Prev[i] = dp[i];
    }
    for (int i=MaxSum/2; i>=0; i--)
        if (dp[i])
            return (MaxSum - 2*i);
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
