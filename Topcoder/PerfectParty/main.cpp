#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
using namespace std;
class PerfectParty {
public:
    int n;
    long long dp[51][51][51];
    long long invite(vector<int> candies) {
        n = candies.size();
        long long ans = 0;
        for (int k=1; k<=n; k++) {
            memset(dp, 0, sizeof(dp));
            dp[0][0][0] = 1;
            for (int j=1; j<=k; j++) {
                for (int i=0; i<=n; i++) {
                    for (int r=0; r<k+1; r++) {
                        for (int t=0; t<i; t++)
                            dp[j][i][r] += dp[j-1][t][(r - (candies[i-1]%(k+1)) + (k+1))%(k+1)];
                    }
                }
            }
            for (int i=1; i<=n; i++)
                ans += dp[k][i][0];
        }
        return ans + 1LL;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> inp;
    for (int i=0; i<n; i++) {
        int ai;
        cin >> ai;
        inp.push_back(ai);
    }
    PerfectParty x;
    cout << x.invite(inp);
    return 0;
}
