#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;

int BinToDec(string s) {
    int x, ans = 0, d = 1;
    for (int i = s.length()-1; i > 0; i--) {
        d = d*2;
    }
    for (int i = 1; i <= s.length(); i++) {
        string tmps = s.substr(i-1,1);
        stringstream tmp(tmps);
        tmp >> x;
        ans = ans + x*d;
        d =d/2;
    }
    return ans;
}

int main()
{
    string s;
    freopen("nhi_thap.inp", "r", stdin);
    freopen("nhi_thap.out", "w", stdout);
    cin >> s;
    cout << BinToDec(s);
    return 0;
}
