#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;

int main()
{
    cout << "Nhap hai so: ";
    cin >> a >> b;
    cout << setw(9) << a << '\n';
    cout<< "+\n" << setw(9) << b << '\n';
    cout << "----------" << '\n';
    cout << setw(9) << a+b << '\n';
    return 0;
}
