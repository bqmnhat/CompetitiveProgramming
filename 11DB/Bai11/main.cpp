#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double F;

int main()
{
    cout << "Hay nhap chi so nhiet do theo do Fahrenheit: ";
    cin >> F;
    double ans = (5.0*(F - 32.0))/9.0;
    cout << "Chi so nhiet do theo do Celcius tuong ung: " << ans;
    return 0;
}
