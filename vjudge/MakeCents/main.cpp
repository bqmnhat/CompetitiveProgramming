#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
int t, c, n;
unordered_map<ll, ld> ma;
const ll Base = 41;

ll HashVal(char c[11]) {
    ll ans = 0;
    int l = s.length();
    for (int i=0; i<l; i++)
        ans = ans*Base + (s[i] - 'A' + 1);
    return ans;
}

void ReadCurrencyChanges() {
    string s;
    ld x;
    for (int i=1; i<=c; i++) {
        cin >> s >> x;
        ma[HashVal(s)] = x;
    }
}

ld Solution() {
    ld ans = 0, x;
    string s;
    for (int i=1; i<=n; i++) {
        cin >> x >> s;
        ans += (ma[HashVal(s)]*x);
    }
    return ans;
}

void Solve() {
    string tmp = "JD";
    ma[HashVal(tmp)] = 1;
    for (int i=1; i<=t; i++) {
        scanf("%ld%ld", &c, &n);
        ReadCurrencyChanges();
        ld tmp = Solution();
        printf("%.6lf\n", &tmp);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%ld", &t);
    Solve();
    return 0;
}
