#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int q;
ll n, m;

ll Solution() {
    return ((m*n)%Mod + ((((n%Mod)*((m+1LL)%Mod))%Mod)*(m-2))%Mod + (n + 1LL)%Mod)%Mod;
}

void Solve() {
    for (int i=1; i<=q; i++) {
        cin >> n >> m;
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    Solve();
    return 0;
}
