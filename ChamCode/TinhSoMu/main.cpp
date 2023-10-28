#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a;

void Solve() {
    int ans = a;
    for (int i=2; i<=3; i++) {
        ans = ans*a;
        cout << ans << " ";
    }
    ans = ans*a;
    cout << ans;
}

int main()
{
    cin >> a;
    Solve();
    return 0;
}
