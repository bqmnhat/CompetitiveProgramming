#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
ll n, m;

void Solve() {
    for (int i=1; i<=q; i++) {
        cin >> n >> m;
        if (n < m)
            swap(n, m);
        if (n%m == 0) {
            cout << "copium\n";
            continue;
        }
        int Winner = 1;
        while ((n/m == 1LL) && (n%m != 0LL)) {
            ll tmp = m;
            m = n%m;
            n = tmp;
            Winner = (1 - Winner);
        }
        if (Winner)
            cout << "copium\n";
        else
            cout << "illya\n";
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
