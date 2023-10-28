#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxX 1000000
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int n, x;
ll c[MaxN+5], dp[MaxX+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> c[i];
}

ll Solution() {
    dp[0] = 1;
    for (int i=1; i<=x; i++)
        for (int j=1; j<=n; j++)
            if (i - c[j] >= 0)
                dp[i] = (dp[i] + dp[i-c[j]])%Mod;
    return dp[x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    ReadData();
    cout << Solution();
    return 0;
}
