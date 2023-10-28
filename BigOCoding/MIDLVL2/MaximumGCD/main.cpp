#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll a[101];
string s;

void SplitData() {
    m=0;
    int val = 0;
    for (int i=0; i<s.length(); i++) {
        if (s[i] != ' ')
            val = val*10 + (s[i]-'0');
        else {
            m++;
            a[m] = val;
            val = 0;
        }
    }
    if (val > 0) {
        m++;
        a[m] = val;
    }
}

ll SolutionForTestCase() {
    ll ans = 0;
    for (int i=1; i<=m; i++) {
        for (int j=i+1; j<=m; j++) {
            ans = max(ans, __gcd(a[i], a[j]));
        }
    }
    return ans;
}

void Solve() {
    cin.ignore();
    for (int i=1; i<=n; i++) {
        getline(cin, s);
        SplitData();
        cout << SolutionForTestCase() << '\n';
    }
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
