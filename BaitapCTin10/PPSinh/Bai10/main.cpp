#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[101], la;

int NextSum(int k) {
    la = 0, ans = 0;
    while (k > 0) {
        int tmp = (k&1);
        k = (k>>1);
        la++;
        if (tmp == 1) {
            ans = ans + la;
            a[n - la] = 1;
        }
        else
            a[n - la] = 0;
    }
    return ans;
}

void Solve() {
    int tmp = (1<<n);
    for (int i=1; i<tmp; i++) {
        if (NextSum(i) == n) {
            for (int j=1; j<=la; j++) {
                cout << a[j] << ' ';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BSTR.INP", "r", stdin);
    freopen("BSTR.OUT", "w", stdout);
    cin >> n;
    s = "";
    for (int i = 1; i <= n; i++)
        s.push_back('0');
    Solve();
    return 0;
}
