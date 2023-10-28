#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, Tong, Hieu, Tich;
double Thuong;

void Solve() {
    cout << "Hay nhap vao 2 so nguyen: ";
    cin >> a >> b;
    Tong = a + b;
    Hieu = a - b;
    Tich = a*b;
    Thuong = double(double(a)/double(b));
    cout << "2 so tren co: \n";
    cout << "- Tong = " << a << " + " << b << " = " << Tong << '\n';
    cout << "- Hieu = " << a << " - " << b << " = " << Hieu << '\n';
    cout << "- Tich = " << a << " * " << b << " = " << Tich << '\n';
    cout << "- Thuong = " << a << " / " << b << " = " << Thuong << '\n';
    cout << "Chuong trinh hoan thanh. Cam on cac ban da su dung.";
}

int main()
{
    Solve();
    return 0;
}
