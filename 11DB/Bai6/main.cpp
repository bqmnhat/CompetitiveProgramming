#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double a, b;

double RecArea(double w, double h) {
    return (w * h);
}

int main()
{
    cout << "Nhap chieu dai: ";
    cin >> a;
    cout << "Nhap chieu rong: ";
    cin >> b;
    cout << "Dien tich HCN la: " << RecArea(b, a);
    return 0;
}
