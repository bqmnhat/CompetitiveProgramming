#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, primes[23] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79};
ll dp[1001];
map <pii, pii> trace;

void Init() {
    for (int i=0; i<=n; i++)
        dp[i] = 1;
}

void Solve() {
    for (int p = 1; p <= 22; p++) {
        for (int i=n; i>=primes[p]; i--) {
            int tmp = 1;
            while (tmp <= i) {
                if (dp[i - tmp]*tmp > dp[i]) {
                    dp[i] = dp[i-tmp]*tmp;
                    trace[{dp[i], i}] = {dp[i-tmp], tmp};
                }
                tmp = tmp*primes[p];
            }
        }
    }
    cout << dp[n] << '\n';
    /*int i = n, a[1001], la = 0, tmpdp = dp[n];
    pii tmp = trace[{tmpdp, i}];
    while (tmp != pii(0, 0)) {
        la++;
        a[la] = tmp.second;
        i = i - tmp.second;
        tmpdp = tmp.first;
        tmp = trace[{tmpdp, i}];
    }
    while (i > 0) {
        la++;
        a[la] = 1;
        i--;
    }
    sort(a+1, a+1+la);
    int pre = 1;
    for (int i=1; i<=la; i++) {
        cout << pre + a[i] - 1 << ' ';
        for (int j=pre; j<pre + a[i] - 1; j++)
            cout << j << ' ';
        pre += a[i];
    }*/
}

/*void SolveAll() {
    for (n=1; n<=80; n++) {
        Init();
        trace.clear();
        cout << "n = " << n << ": \n";
        Solve();
        cout << '\n';
    }
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    cin >> n;
    Init();
    Solve();
    return 0;
}
