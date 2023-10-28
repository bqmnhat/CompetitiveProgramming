#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n;

void SolveTestCases() {
    if ((n%4 == 0) || (n%4 == 2))
        cout << n-3 << ' ' << "2 1";
    else if (n%4 == 1)
        cout << (n/2)-1 << ' ' << (n/2)+1 << ' ' << 1;
    else
        cout << (n/2)-2 << ' ' << (n/2)+2 << ' ' << 1;
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        SolveTestCases();
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
