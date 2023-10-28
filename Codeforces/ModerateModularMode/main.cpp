#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int x, y,t;

int NumMustBeFound() {
    if (x <= y)
        return (y - (y%x)/2);
    else
        return (x+y);
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> x >> y;
        cout << NumMustBeFound() << '\n';
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
