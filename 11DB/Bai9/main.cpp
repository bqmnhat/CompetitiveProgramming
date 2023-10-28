#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double a, b;

void Solve(double a, double b) {
    if (a == 0) {
        if (b == 0) {
            cout << "Phuong trinh co vo so nghiem";
            return;
        }
        else {
            cout << "Phuong trinh vo nghiem";
            return;
        }
    }
    else
        cout << "Phuong trinh co nghiem la: " << -b/a;
}

int main()
{
    cout << "Giai phuong trinh ax + b = 0.\nHay nhap he so a: ";
    cin >> a;
    cout << "Hay nhap he so b: ";
    cin >> b;
    Solve(a, b);
    return 0;
}
