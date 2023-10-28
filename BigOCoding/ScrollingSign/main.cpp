#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k, w;

vector<int> MakeZFunction(string s) {
    int len = 2*k+1;
    vector<int> z(len, 0);
    int l = 0, r = 0;
    z[0] = len;
    for (int i=1; i<len; i++) {
        if (i <= r)
            z[i] = min(z[i-l], r-i+1);
        while ((i + z[i] < len) && (s[i+z[i]] == s[z[i]]))
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int MaxCommonPref(string s1, string s2) {
    string tmp = s1 + "#" + s2;
    vector<int> z = MakeZFunction(tmp);
    int ans = 0;
    for (int i=k+1; i<2*k+1; i++)
        if (i + z[i] - 1 == 2*k)
            ans = max(ans, z[i]);
    return ans;
}

int Solution() {
    string s1, s2;
    cin >> k >> w >> s1;
    int ans = k;
    for (int i=2; i<=w; i++) {
        cin >> s2;
        int tmp = MaxCommonPref(s2, s1);
        ans += (k - tmp);
        s1 = s2;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=n; i++)
        cout << Solution() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Solve();
    return 0;
}
