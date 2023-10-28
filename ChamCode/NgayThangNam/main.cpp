#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string d,m,y;

void Solve() {
    while (d.length() < 2)
        d = "0" + d;
    while (m.length() < 2)
        m = "0" + m;
    while (y.length() < 4)
        y = "0" + y;
    cout << d << "/" << m << "/" << y;
}

int main()
{
    cin >> d >> m >> y;
    Solve();
    return 0;
}
