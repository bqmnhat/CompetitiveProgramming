#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double r, c = 4.0/3.0, pi = 3.14;

int main()
{
    cin >> r;
    cout << fixed << setprecision(2) << 4*pi*(r*r) << " " << c*pi*(r*r*r);
    return 0;
}
