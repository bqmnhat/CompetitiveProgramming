#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n;

int Solution() {
    int ai, ans = 0;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        ans = max(ans, ai - i);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << Solution() << '\n';
    }
    return 0;
}
