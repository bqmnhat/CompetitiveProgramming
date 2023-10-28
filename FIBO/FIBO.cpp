#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string f[1001];
int n;

string Sum(string f1,string f2) {
    int carry = 0,x,y,sum;
    string ans = "";
    while (f1.length() < f2.length())
        f1 = '0' + f1;
    while (f2.length() < f1.length())
        f2 = '0' + f2;
    for (int i = f1.length()-1; i>=0; --i) {
        x = int(f1[i] - '0');
        y = int(f2[i] - '0');
        sum = x + y + carry;
        carry = sum / 10;
        ans = char(sum%10 + 48) + ans;
    }
    if (carry > 0) {
        ans = '1' + ans;
    }
    return ans;
}

void FiboN() {
    f[1] = "1";
    f[2] = "1";
    string fn = "";
    for (int i=3; i<=1000; i++) {
        f[i] = Sum(f[i-1],f[i-2]);
    }
}

int main()
{
    freopen("FIBO.INP", "r", stdin);
    freopen("FIBO.OUT", "w", stdout);
    FiboN();
    while (cin >> n)
        cout << f[n] << endl;
    return 0;
}
