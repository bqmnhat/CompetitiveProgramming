#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int t, n;

void Solve() {
    if (n == 1) {
        cout << "a" << '\n';
        return;
    }
    int k = n / 2;
    string ans = "";
    for (int i = 1; i <= k; i++)
        ans = ans + 'a';
    if (n % 2 == 0)
        ans = ans + 'b';
    else
        ans = ans + "bc";
    for (int i = 1; i <= k - 1; i++)
        ans = ans + 'a';
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        Solve();
    }
    return 0;
}
