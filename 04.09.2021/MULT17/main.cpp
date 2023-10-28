#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string x;

string LShift(string x, int nos) {
    string ans = x;
    for (int i=1; i<=nos; i++) {
        ans = ans + '0';
    }
    return ans;
}

string Add(string a, string b) {
    string ans = "";
    while (a.length() < b.length())
        a = '0' + a;
    while (b.length() < a.length())
        b = '0' + b;
    int r = 0;
    for (int i=a.length() - 1; i>=0; i--) {
        int tmp = (a[i] - '0') + (b[i] - '0') + r;
        r = tmp/2;
        tmp = tmp%2;
        ans = char(tmp + '0') + ans;
    }
    if (r == 1)
        ans = char(r + '0') + ans;
    return ans;
}

int main()
{
    freopen("MULT17.INP", "r", stdin);
    freopen("MULT17.OUT", "w", stdout);
    cin >> x;
    cout << Add(LShift(x,4),x);
    return 0;
}
