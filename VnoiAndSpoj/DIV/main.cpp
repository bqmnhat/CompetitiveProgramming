#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int q;
ll a, b;

void Solve() {
    for (int i=1; i<=q; i++) {
        ll Sign = 1;
        cin >> a >> b;
        if (a < 0)
            Sign *= (-1LL);
        if (b < 0)
            Sign *= (-1LL);
        a = abs(a);
        b = abs(b);
        ll GCD = __gcd(a, b);
        a /= GCD;
        b /= GCD;
        ll First = 0, Second = 0;
        if (Sign < 0) {
            if (a < b)
                a = a*Sign;
            else
                b = b*Sign;
        }
        First = a;
        Second = b;
        if (First + Second <= 0) {
            cout << "0 0\n";
            continue;
        }
        cout << First << ' ' << Second << '\n';
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
