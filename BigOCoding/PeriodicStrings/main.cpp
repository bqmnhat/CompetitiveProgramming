#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
string s;

vector<int> MakeZFunction(string s) {
    int n = s.length(), l = 0, r = 0;
    vector<int> z(n);
    z[0] = n;
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

bool CheckPeriod(const vector<int>& z, int n, int p) {
    int i = 0;
    while (i < n) {
        if (z[i] < p)
            return false;
        i += p;
    }
    return true;
}

int MinPeriod(string s) {
    int n = s.length();
    int ans = n;
    vector<int> z = MakeZFunction(s);
    for (int i=1; i<=n; i++) {
        if ((n%i == 0) && (CheckPeriod(z, n, i))) {
            ans = i;
            break;
        }
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        if (i > 1)
             cout << '\n';
        cin >> s;
        cout << MinPeriod(s) << '\n';
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
