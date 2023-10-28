#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n;

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ll Odd = (1LL << (__builtin_popcountll(n)));
        ll Even = n+1LL-Odd;
        cout << Even << ' ' << Odd << '\n';
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
