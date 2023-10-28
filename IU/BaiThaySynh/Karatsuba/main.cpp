#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MakeEqualLens(string& x, string& y) {
    while (x.length() < y.length())
        x = '0' + x;
    while (x.length() > y.length())
        y = '0' + y;
    return x.length();
}

string Add(string a, string b) {
    string ans = "";
    int l = MakeEqualLens(a, b), carry = 0;
    for (int i=l-1; i>=0; i--) {
        int FirstBit = a[i] - '0', SecondBit = b[i] - '0';
        int Sum = ((FirstBit + SecondBit + carry)%10) + '0';
        ans = char(Sum) + ans;
        carry = (FirstBit + SecondBit + carry)/10;
    }
    if (carry > 0)
        ans = '1' + ans;
    return ans;
}

int SingleMul(const string& a,const string& b) {
    return ((a[0] - '0')*(b[0] - '0'));
}

string DecToStr(ll num) {
    string ans = "";
    if (num <= 0)
        return "0";
    else {
        stringstream ss;
        ss << num;
        ans = ss.str() + ans;
        return ans;
    }
}

string MakeShift(string x, int step) {
    string shifted = x;
    for (int i=0; i < step; i++)
        shifted = shifted + '0';
    return shifted;
}

bool IsSmaller(string a, string b) {
    int la = a.length(), lb = b.length();
    if (la < lb)
        return true;
    else if (la > lb)
        return false;
    return (a < b);
}

string Subtract(string a, string b) {
    if (IsSmaller(a, b))
        swap(a, b);
    string ans = "";
    int la = a.length(), lb = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    for (int i=0; i<lb; i++) {
        int sub = (a[i] - '0') - (b[i] - '0') - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        }
        else
            carry = 0;
        ans.push_back(sub + '0');
    }
    for (int i=lb; i<la; i++) {
        int sub = (a[i] - '0') - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        }
        else
            carry = 0;
        ans.push_back(sub + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string Mult(string a, string b) {
    int l = MakeEqualLens(a, b);
    if (l == 0)
        return "0";
    if (l == 1)
        return DecToStr((a[0]-'0') * (b[0] - '0'));
    int FirstHalf = l/2;
    int SecondHalf = l-FirstHalf;
    string al = a.substr(0, FirstHalf), ar = a.substr(FirstHalf, SecondHalf), bl = b.substr(0, FirstHalf), br = b.substr(FirstHalf, SecondHalf);
    string P1 = Mult(al, bl);
    string P2 = Mult(ar, br);
    string sumA = Add(al, ar);
    string sumB = Add(bl, br);
    string P3 = Mult(sumA,sumB);
    return Add(Add(MakeShift(P1, 2*SecondHalf), P2), MakeShift(Subtract(P3, Add(P1, P2)),SecondHalf));
}

int main()
{
    string a1 = "7896", a2 = "4876";
    cout << Mult(a1, a2);
    return 0;
}
