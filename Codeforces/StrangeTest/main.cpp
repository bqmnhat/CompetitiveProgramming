#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, a, b;

int FindBDash(int a, int b) {
    int cnt = 0, tmp1, tmp2, ans = 0;
    while ((a > 0) && (b > 0)) {
        tmp1 = a%2;
        tmp2 = b%2;
        if (tmp1 == 1) {
            ans += (1 << cnt);
            if (tmp2 == 0)
                break;
        }
        else {
            if(tmp2 == 1)
                ans += (1 << cnt);
        }
        a = a/2;
        b = b/2;
        cnt++;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> a >> b;
        int ans = (a|FindBDash(a,b)) + (1 - b);
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
