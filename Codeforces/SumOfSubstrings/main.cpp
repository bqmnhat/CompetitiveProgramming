#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int t, n, k;
string s;

int Solution() {
    int FirstOne = -1, LastOne = -1, cnt1 = 0, ans = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '1') {
            cnt1++;
            LastOne = i;
            if (FirstOne == -1)
                FirstOne = i;
        }
    }
    if ((cnt1 > 0) && (k - n + 1 + LastOne >= 0)) {
        ans++;
        cnt1--;
        k -= (n - 1 - LastOne);
    }
    if ((cnt1 > 0) && (k - FirstOne >= 0)) {
        ans+=10;
        cnt1--;
        k -= FirstOne;
    }
    ans += (11*cnt1);
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
