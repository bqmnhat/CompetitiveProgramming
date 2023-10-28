#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool b[42];

int Solution() {
    int ans = 0, a;
    while (cin >> a) {
        if (b[a%42] == false) {
            ans++;
            b[a%42] = true;
        }
    }
    return ans;
}

int main()
{
    freopen("SODU.INP", "r", stdin);
    freopen("SODU.OUT", "w", stdout);
    cout << Solution();
    return 0;
}
