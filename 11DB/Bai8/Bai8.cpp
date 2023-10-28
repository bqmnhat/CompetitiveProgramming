#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double a, b, h;

double Solution(double a, double b, double c) {
    return ((a+b)*h)/2.0;
}

int main()
{
    cout << "Hay nhap day lon: ";
    cin >> a;
    cout << "Hay nhap day be: ";
    cin >> b;
    cout << "Hay nhap chieu cao: ";
    cin >> h;
    cout << Solution(a, b, h);
    return 0;
}
