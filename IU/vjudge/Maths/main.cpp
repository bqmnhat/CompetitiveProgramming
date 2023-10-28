#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n;

int Solution() {
    int ans = 0, x = n;;
    for (int i=2; i*i <= n; i++) {
        while (x % i == 0) {
            ans += (i-1);
            x = x/i;
        }
    }
    ans += x;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << Solution() << '\n';
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
