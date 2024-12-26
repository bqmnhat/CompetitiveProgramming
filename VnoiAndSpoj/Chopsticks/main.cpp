#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int t, n;
ll cnt[3];

void Solve() {
    for (int id=1; id<=t; id++) {
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for (int i=1; i<=n; i++) {
            ll ai;
            cin >> ai;
            if (ai > 2) {
                cnt[1] += ai-2;
                ai = 2;
            }
            cnt[ai]++;
        }
        ll ans = (cnt[1]/2) + (cnt[2]/2);
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
