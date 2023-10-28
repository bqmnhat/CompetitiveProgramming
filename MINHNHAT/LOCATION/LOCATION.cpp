#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k;

int LengthOfA(int a) {
    int ans = 0;
    while (a > 0) {
        a = a/10;
        ans = ans + 1;
    }
    return ans;
}

void Solve() {
    int l = LengthOfA(n);
    int m = l - k;
    if (m < 0) {
        cout << "NO";
        return;
    }
    if (k == 0) {
        cout << "NO";
        return;
    }
    for (int i=1; i<=m; i++) {
        n = n/10;
    }
    cout << n%10;
}

int main()
{
    freopen("LOCATION.INP", "r", stdin);
    freopen("LOCATION.OUT", "w", stdout);
    cin >> n >> k;
    Solve();
    return 0;
}
