#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int n, k, t;
string s;

string Solution() {
    string ans = "";
    for (int i=0; i<n; i++) {
        int step = min(s[i] - 'a', k);
        k -= step;
        char c = s[i] - step;
        ans = ans + c;
    }
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
