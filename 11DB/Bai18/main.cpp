#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a, b;

void Swap(int& a, int& b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int tmp;
    cout << "Hay nhap vao 2 so nguyen: ";
    cin >> a >> b;
    Swap(a, b);
    cout << "Gia tri da duoc hoan vi: " << a << ' ' << b;
    return 0;
}
