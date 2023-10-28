#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double m, h;

int main()
{
    cout << "Tinh BMI.\nHay nhap khoi luong (kg): ";
    cin >> m;
    cout << "Hay nhap chieu cao (m): ";
    cin >> h;
    if (h == 0)
        cout << "Khong ton tai chi so BMI tuong ung.";
    else {
        double ans = m/(h*h);
        cout << "Chi so BMI cua ban la: " << ans;
    }
    return 0;
}
