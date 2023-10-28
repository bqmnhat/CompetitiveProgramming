#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
double d;

void Solve() {
    double s = 0, p = 0;
    cout << "Hay nhap ban kinh hinh tron: ";
    cin >> d;
    s = d*d*pi;
    p = 2.0*d*pi;
    cout << "Dien tich hinh tron: " << s << '\n';
    cout << "Chu vi hinh tron: " << p << '\n';
}

int main()
{
    Solve();
    return 0;
}
