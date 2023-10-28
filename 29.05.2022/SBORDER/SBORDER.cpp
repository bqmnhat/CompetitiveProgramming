#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int n;
string s;
int z[MaxN+1];

void MakeZFunction(string s, int n) {
    z[0] = n;
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
        if (i <= r)
            z[i] = min(z[i-l], r - i + 1);
        while ((i + z[i] < n) && (s[z[i]] == s[i + z[i]]))
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

void Solve() {
    n = s.length();
    int ans = 0;
    MakeZFunction(s, n);
    for (int i=1; i<n; i++)
        if (z[n-i] == i)
            cout << i << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SBORDER.INP", "r", stdin);
    freopen("SBORDER.OUT", "w", stdout);
    cin >> s;
    Solve();
    return 0;
}
