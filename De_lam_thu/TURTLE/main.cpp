#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a,b,s;

void Solve() {
    if ((s - (a+b) >= 0 ) && ((s - (a+b)) % 2 == 0)) {
        cout << "YES";
    }
    else
        cout << "NO";
    cout << endl;
}

int main()
{
    freopen("TURTLE.INP", "r", stdin);
    freopen("TURTLE.OUT", "w", stdout);
    while (cin >> a >> b >> s) {
        Solve();
    }
    return 0;
}
