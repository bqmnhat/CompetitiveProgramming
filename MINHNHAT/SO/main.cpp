#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string a,b;

int Comp(string a, string b) {
    int l1 = a.length(), l2 = b.length(), l = abs(l1-l2);
    if (l1 < l2)
        return -1;
    if (l1 > l2)
        return 1;
    if (a == b)
        return 0;
    if (a < b)
        return -1;
    if (a>b)
        return 1;
}

int main()
{
    freopen("SO.INP", "r", stdin);
    freopen("SO.OUT", "w", stdout);
    cin >> a >> b;
    cout << Comp(a,b);
    return 0;
}
