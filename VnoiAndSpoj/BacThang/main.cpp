#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
const ll Mod = 14062008;
int n, k;
ll dp[MaxN+5];
bool NotWorking[MaxN+5];

void ReadData() {
    int ai;
    for (int i=1; i<=k; i++) {
        cin >> ai;
        NotWorking[ai] = true;
    }
}

ll Solution() {
    dp[1] = 1;
    for (int i=2; i<=n; i++) {
        if (NotWorking[i])
            continue;
        dp[i] = (dp[i] + dp[i-1] + dp[i-2])%Mod;
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    cout << Solution();
    return 0;
}
