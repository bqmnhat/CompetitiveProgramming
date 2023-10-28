#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000000
using namespace std;
typedef long long ll;
int t;
ll dp[MaxN+1], Mod = 1e9 + 7;
bool IsRootYellow[MaxN+1];

void MakeDp() {
    for (int i=3; i<=MaxN; i++) {
        if ((!IsRootYellow[i-1]) && (!IsRootYellow[i-2])) {
            dp[i] = ((dp[i-1]%Mod) + ((2*dp[i-2])%Mod) + 4)%Mod;
            IsRootYellow[i] = true;
        }
        else
            dp[i] = ((dp[i-1]%Mod) + ((2*dp[i-2])%Mod))%Mod;
    }
}

void Solve() {
    int lvl;
    for (int i=1; i<=t; i++) {
        cin >> lvl;
        cout << dp[lvl] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeDp();
    cin >> t;
    Solve();
    return 0;
}
