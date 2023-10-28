#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
long long x,y;

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> x >> y;
        if (x%2 == 0) {
            if ((x == 0) && (y%2 == 1))
                cout << "NO";
            else
                cout << "YES";
        }
        else
            cout << "NO";
        cout << '\n';
    }
}

int main()
{
    cin >> t;
    Solve();
    return 0;
}
