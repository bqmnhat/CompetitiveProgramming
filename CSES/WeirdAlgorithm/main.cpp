#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

void Solve() {
    while (n != 1LL) {
        cout << n << ' ';
        if (n&1LL)
            n = n*3 + 1LL;
        else
            n >>= 1LL;
    }
    cout << 1;
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
