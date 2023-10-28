#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
int n, res[MaxN+5];
string s;
vector<int> a;

void PreprocessData() {
    n = s.length();
    for (int i=n-1; i>=0; i--)
        a.push_back(s[i] - '0');
    a.push_back(-1);
    for (int i=1; i<=n; i++)
        a.push_back(7);
    reverse(a.begin(), a.end());
}

vector<int> FindZ(const vector<int>& a) {
    vector<int> z(a.size(), 0);
    z[0] = a.size();
    int l = 0, r = 0;
    for (int i=1; i<a.size(); i++) {
        if (i <= r)
            z[i] = min(z[i-l], r - i + 1);
        while ((i + z[i] < a.size()) && (a[z[i]] == a[i + z[i]]))
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

void Solve() {
    vector<int> z = FindZ(a);
    for (int i=n+1; i<z.size(); i++) {
        res[1]++;
        res[z[i] + 1]--;
    }
    for (int i=1; i<=n; i++) {
        res[i] += res[i-1];
        if (res[i] != 0)
            cout << i << ' ' << res[i] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    PreprocessData();
    Solve();
    return 0;
}
