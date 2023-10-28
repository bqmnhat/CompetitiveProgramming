#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll X1, Y1, X2, Y2;

ll Solution() {
    return (((Y2 - Y1) * (X2 - X1)) + 1);
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> X1 >> Y1 >> X2 >> Y2;
        cout << Solution() << '\n';
    }
}

int main()
{
    cin >> t;
    Solve();
    return 0;
}
