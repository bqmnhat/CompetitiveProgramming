#include <iostream>
#define MaxN 3000
using namespace std;
string s, t;
int dp[MaxN+1][MaxN+1];

void Solve() {
    int ns = s.length(), nt = t.length();
    for (int i=1; i<ns; i++) {
        for (int j=1; j<nt; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s[i] == t[j])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    int i = ns-1, j = nt-1;
    string ans = "";
    while ((i > 0) && (j > 0)) {
        if ((dp[i][j] == dp[i-1][j-1] + 1) && (s[i] == t[j])) {
            ans = s[i] + ans;
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i][j-1])
            j--;
        else
            i--;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    s = ' ' + s;
    t = ' ' + t;
    Solve();
    return 0;
}
