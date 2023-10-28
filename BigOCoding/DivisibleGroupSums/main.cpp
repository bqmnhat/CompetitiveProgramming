#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, Q, D, M, dp[201][11][21], a[201];

void ReadA() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll CalDp() {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (ll i=1; i<=n; i++) {
        for (ll j=0; j<=M; j++) {
            for (ll t = 0; t < D; t++) {
                ll tmp = (t + a[i])%D;
                if (tmp < 0)
                    tmp += D;
                dp[i][j][t] += dp[i-1][j][t];
                if (j != 0)
                    dp[i][j][t] += dp[i-1][j-1][tmp];
            }
        }
    }
    return dp[n][M][0];
}

void SolveTestCase() {
    for (int i = 1; i<=Q; i++) {
        cin >> D >> M;
        cout << "QUERY " << i << ": " << CalDp() << '\n';
    }
}

void Solve() {
    cin >> n >> Q;
    int cnt = 0;
    while ((n != 0) && (Q != 0)) {
        ReadA();
        cnt++;
        cout << "SET " << cnt << ":\n";
        SolveTestCase();
        cin >> n >> Q;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
