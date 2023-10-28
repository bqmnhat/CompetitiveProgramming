#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x,n,p[10], lp = 0;
ll dp[10][1000001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> p[i];
}

void EraseUnique() {
    lp++;
    p[lp] = p[1];
    for (int i=2; i<=n; i++) {
        if (p[i] != p[i-1]) {
            lp++;
            p[lp] = p[i];
        }
    }
}

ll TotalCombinations() {
    for(int i = 0; i<=lp; i++)
        dp[i][0] = 1;
    for (int i=1; i<=lp; i++) {
        for (int j=1; j<=x; j++) {
            dp[i][j] += dp[i-1][j];
            ll t = 1;
            while ((j - (t*p[i])) >= 0) {
                dp[i][j] += dp[i-1][j-(t*p[i])];
                t++;
            }
        }
    }
    return dp[lp][x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> n;
    ReadData();
    sort(p+1, p+1+n);
    EraseUnique();
    cout << TotalCombinations();
    return 0;
}
