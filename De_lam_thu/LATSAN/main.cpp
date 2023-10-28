#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long g,y,m,n;

void Solve() {
    long long delta = (g/2 + 2)*(g/2 + 2) - 4*(g+y);
    m = ((g/2 + 2) - sqrt(delta))/2;
    n = ((g/2 + 2) + sqrt(delta))/2;
    cout << m << " " << n;
}

int main()
{
    freopen("LATSAN.INP", "r", stdin);
    freopen("LATSAN.OUT", "w", stdout);
    cin >> g >> y;
    Solve();
    return 0;
}
