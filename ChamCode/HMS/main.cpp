#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a;

void Solve() {
    long long h,m,s;
    h = a/3600;
    a = a%3600;
    m = a/60;
    a = a%60;
    s = a;
    if (h < 10)
        cout << "0";
    cout << h << ":";
    if (m < 10)
        cout << "0";
    cout << m << ":";
    if (s < 10)
        cout << "0";
    cout << s;
}

int main()
{
    cin >> a;
    Solve();
    return 0;
}
