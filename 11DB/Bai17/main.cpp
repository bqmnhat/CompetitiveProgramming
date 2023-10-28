#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
double r;

int main()
{
    cout << "Hay nhap vao ban kinh hinh cau (dvdd): ";
    cin >> r;
    double S = 4*pi*(r*r);
    double V = (4.0/3.0)*pi*(r*r*r);
    cout << "Dien tich hinh cau: " << S << '\n';
    cout << "The tich hinh cau: " << V;
    return 0;
}
