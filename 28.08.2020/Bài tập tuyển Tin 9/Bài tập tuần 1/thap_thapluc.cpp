#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;

string DecToHex(int n) {
    string a = "ABCDEF";
    stringstream ss;
    string s,tmp = "";
    int x;
    while (n > 0) {
        x = n%16;
        n = n/16;
        ss << x;
        s = ss.str();
        if (x > 9)
            s = a.substr(x-10,1);
        tmp = s + tmp;
        ss.str(string());
    }
    return tmp;
}

int main()
{
    int n;
    freopen("thap_thapluc.inp", "r", stdin);
    freopen("thap_thapluc.out", "w", stdout);
    cin >> n;
    cout << DecToHex(n);
    return 0;
}
