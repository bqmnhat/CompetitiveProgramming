#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n;
int q;

void Solve() {
    long long ans = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            ans++;
            n = n/2;
        }
        else if (n % 5 == 0) {
            ans++;
            n = (n*4)/5;
        }
        else if (n%3 == 0) {
            ans++;
            n = (n*2)/3;
        }
        else {
            cout << "-1" << '\n';
            return;
        }
    }
    cout << ans << '\n';
}

int main()
{
    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> n;
        Solve();
    }
    return 0;
}
