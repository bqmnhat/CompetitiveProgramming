#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxM 100
using namespace std;
int dp[MaxN+5][MaxM+5];
bool FoundAns = true;
int t, OriN, m;

int CalDp(int n, int mv) {
    if (mv == m)
        return dp[n][mv] = (n > OriN);
    if (dp[n][mv] != -1)
        return dp[n][mv];
    for (int i=1; i<=4; i++) {
        int cnt = 0, tmp = n;
        int NxtN = 0, base = 1;
        while (cnt < 4) {
            cnt++;
            int CurDig = tmp%10;
            if (cnt == i)
                CurDig = (CurDig + 1)%10;
            NxtN = CurDig*base + NxtN;
            base *= 10;
            tmp /= 10;
        }
        if (mv % 2 == 1) {
            if (CalDp(NxtN, mv+1) == 0)
                return dp[n][mv] = 0;
        }
        else if (CalDp(NxtN, mv+1) == 1)
            return dp[n][mv] = 1;
    }
    return dp[n][mv] = (mv % 2);
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> OriN >> m;
        memset(dp, -1, sizeof(dp));
        if (CalDp(OriN, 0))
            cout << "Ada";
        else
            cout << "Vinit";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
