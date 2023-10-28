#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll G, L;

void Solve() {
    for (int i=1; i<=T; i++) {
        cin >> G >> L;
        bool Found = false;
        ll Product = G*L;
        for (ll a = 1; a <= L; a++) {
            if ((Product%a == 0) && (__gcd(a, Product/a) == G)) {
                Found = true;
                cout << a << ' ' << Product/a;
                break;
            }
        }
        if (!Found)
            cout << "-1";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    Solve();
    return 0;
}
