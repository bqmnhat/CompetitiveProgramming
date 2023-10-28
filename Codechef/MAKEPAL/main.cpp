#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n;

void Solve() {
    int ans;
    for (int i=1; i<=t; i++) {
        ans = 0;
        cin >> n;
        int ai;
        for (int j=1; j<=n; j++) {
            cin >> ai;
            if (ai % 2 == 1)
                ans++;
        }
        ans = ans/2;
        cout << ans << '\n';
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
