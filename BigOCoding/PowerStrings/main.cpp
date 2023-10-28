#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
string s;

vector<int> MakeZFunction(string s) {
    int n = s.length();
    vector<int> z(n, 0);
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

void Solve() {
    while ((cin >> s) && (s != ".")) {
        int l = s.length();
        vector<int> z = MakeZFunction(s);
        int MaxPrefEqualSuff = 0;
        for (int i = 1; i<z.size(); i++)
            MaxPrefEqualSuff = max(MaxPrefEqualSuff, z[i]);
        if (l%(l-MaxPrefEqualSuff))
            cout << 1 << '\n';
        else
            cout << l/(l - MaxPrefEqualSuff) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
