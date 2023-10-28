#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100005
using namespace std;
int n, pref[MaxN+1];
bool IsSuf[MaxN+1];
string s;
vector<int> z;
int q;

vector<int> MakeZ(string s) {
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
        if (i <= r)
            z[i] = min(z[i-l], r - i + 1);
        while ((i + z[i] < n) && (s[i + z[i]] == s[z[i]]))
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

void MakePref() {
    for (int i=0; i<n; i++) {
        pref[z[i]]++;
        if (i + z[i] == n)
            IsSuf[z[i]] = true;
    }
    for (int i=n; i>=1; i--)
        pref[i] += pref[i+1];
}

void Solve() {
    cin >> s >> q;
    z = MakeZ(s);
    n = s.length();
    MakePref();
    for (int i=1; i<=q; i++) {
        int li;
        cin >> li;
        if ((IsSuf[li]) && (pref[li] + 1 >= 3))
            cout << "YES " << pref[li] + 1 << '\n';
        else
            cout << "NO\n";
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
