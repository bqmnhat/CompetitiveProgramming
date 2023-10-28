#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n;

void SolveTestCase() {
    if ((n == 2) || (n == 3))
        cout << "second";
    else
        cout << "first";
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        SolveTestCase();
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
