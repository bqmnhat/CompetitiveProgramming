#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
int t, x;

void SolveTestCase() {
    if (x == 1) {
        cout << "1\n1\n";
        return;
    }
    if (x == 2) {
        cout << "2\n1 2\n";
        return;
    }
    int n = 1;
    while ((1 << n)-2 <= x)
        n++;
    n--;
    cout << n << '\n';
    for (int i=0; i<n; i++)
        cout << (1 << n) - 1 - (1 << i) << ' ';
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> x;
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
