#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("CHIANHOM.INP", "w", stdout);
    cout << 100000 << ' ' << 10000;
    for (int i=1; i<=100000; i++)
        cout << i << ' ';
    cout << '\n';
    int l = 1, r = 100000;
    for (int i=1; i<=10000; i++) {
        cout << l << ' ' << r << '\n';
        l++;
        r--;
    }
    return 0;
}
