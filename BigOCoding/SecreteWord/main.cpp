#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
int t;
string s;

vector<int> MakeZFunction(string s) {
    int n = s.length();
    vector<int> z(n+1, 0);
    z[0] = n;
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
        if (i <= r)
            z[i] = min(z[i-l], r-i+1);
        while ((i + z[i] < n) && (s[i + z[i]] == s[z[i]]))
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int Solution(string s) {
    int n = s.length();
    string s2 = s;
    reverse(s2.begin(), s2.end());
    string tmp = s + "#" + s2;
    int tmplen = tmp.length(), ans = 0;
    vector<int> z = MakeZFunction(tmp);
    for (int i = n+1; i<tmplen; i++)
        ans = max(ans, z[i]);
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
        int tmp = Solution(s), n = s.length();
        for (int i=tmp-1; i>=0; i--)
            cout << s[i];
        cout << '\n';
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
