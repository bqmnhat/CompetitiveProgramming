#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string k, ans, flag = "3";

string Subtract(string a, string b) {// a - b
    string ans = "";
    int borrow = 0,tmp;
    while (a.length() < b.length()) {
        a = "0" + a;
    }
    while (b.length() < a.length()) {
        b = "0" + b;
    }
    for (int i=a.length()-1; i>=0; i--) {
        tmp = a[i] - b[i] - borrow;
        if (tmp < 0) {
            tmp = tmp+10;
            borrow = 1;
        }
        else borrow = 0;
        ans = char(tmp+48) + ans;
    }
    return ans;
}

string Multiply(string a, int b) {
    string ans = "";
    int r = 0, tmp;
    for (int i=a.length()-1; i>=0; i--) {
        tmp = b*(a[i]-'0') + r;
        if (tmp > 9) {
            r = tmp/10;
            tmp = tmp%10;
        }
        ans = char(tmp + '0') + ans;
    }
    if (r > 0)
        ans = char(r + '0') + ans;
    return ans;
}

int main()
{
    freopen("XUATHIEN.INP", "r", stdin);
    freopen("XUATHIEN.OUT", "w", stdout);
    cin >> k;
    cout << Multiply(Subtract(k,flag), 4);
    return 0;
}
