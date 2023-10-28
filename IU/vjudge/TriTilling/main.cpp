#include <iostream>
#define MaxN 30
using namespace std;
typedef long long ll;
int n;
ll dp[MaxN+1] = {-1};

void MakeDp() {
    dp[0] = 1;
    dp[2] = 3;
    for (int i=4; i<=MaxN; i++) {
        if (i % 2)
            continue;
        dp[i] = 4*dp[i-2] - dp[i-4];
    }
}

void Solve() {
    while ((cin >> n) && (n != -1))
        cout << dp[n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeDp();
    Solve();
    return 0;
}
