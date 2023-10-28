#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, k;
string s;

int Solution() {
    int ans = 0, pos1Begin = -1, pos1Last = -1, cnt1 = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '1') {
            cnt1++;
            pos1Last = i;
            if (pos1Begin == -1)
                pos1Begin = i;
        }
    }
    if ((cnt1 > 0) && (k - n + 1 + pos1Last >= 0)) {
        cnt1--;
        ans++;
        k = k - n + 1 + pos1Last;
    }
    if ((cnt1 > 0) && (k - pos1Begin >= 0)) {
        cnt1--;
        ans += 10;
        k = k - pos1Begin;
    }
    ans += (11 * cnt1);
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k >> s;
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
