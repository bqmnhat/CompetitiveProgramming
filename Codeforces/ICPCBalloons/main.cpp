#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, cnt[27];
string s;

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> s;
        int ans = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i=0; i<n; i++) {
            cnt[s[i] - 'A']++;
            ans++;
            if (cnt[s[i] - 'A'] == 1)
                ans++;
        }
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
