#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double a, b, c, p, S;

int main()
{
    cout << "Hay nhap 3 canh cua tam giac (cach nhau boi ' '): ";
    cin >> a >> b >> c;
    p = (a + b + c)/2.0;
    S = sqrt(p * (p-a) * (p-b) * (p-b));
    cout << "Dien tich cua hinh tam giac tuong ung: " << S;
    return 0;
}
