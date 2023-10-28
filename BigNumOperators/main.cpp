#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> BigInt;
// Sum of 2 Big Numbers
BigInt operator + (BigInt a, BigInt b) {
    BigInt ans;
    int i = 0, j = 0, r = 0;
    while ((i < a.size()) || (j < b.size())) {
        if (i < a.size())
            r += a[i++];
        if (j < b.size())
            r += b[j++];
        ans.push_back(r%10);
        r = r/10;
    }
    if (r > 0)
        ans.push_back(r);
    return ans;

}
// Subtraction of 2 Big Numbers
BigInt operator - (BigInt a, BigInt b) {
    BigInt ans;
    int i = 0, j = 0, r = 0;
    while ((i < a.size()) && (j < b.size())) {
        int tmp = a[i++] - r;
        if (j < b.size())
            tmp = tmp - b[j++];
        if (tmp < 0) {
            tmp += 10;
            r = 1;
        }
        else
            r = 0;
        ans.push_back(tmp);
    }
    while (ans.back() == 0)
        ans.pop_back();
    return ans;
}
// Multiplication of 2 Big Numbers
BigInt operator * (BigInt a, int b) // Multiplication of 1 Big Number and 1 integer
{
    BigInt ans;
    int r = 0;
    for (int i = 0; i < a.size(); ++i) {
        r = r + a[i]*b;
        ans.push_back(r%10);
        r = r/10;
    }
    if (r > 0)
        ans.push_back(r);
    return ans;
}
BigInt pow10(BigInt a, int n) { //ham mu 10
    BigInt ans(a.size()+n, 0);
    for (int i = 0, j = n; i < a.size(); ++i, ++j)
        ans[j] = a[i];
    return ans;
}
BigInt operator * (BigInt a, BigInt b) // Multiplication of 2 BigInts
{
    BigInt ans;
    for (int i = 0; i < b.size(); ++i) {
        BigInt tmp = a*b[i]; // Use Multiplication operator of 1 BigInt and 1 integer
        tmp = pow10(tmp, i);
        ans = ans + tmp;
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    BigInt a, b;
    for (int i=s.length()-1; i>=0; i--)
        a.push_back(int(s[i] - '0'));
    cin >> s;
    for (int i=s.length()-1; i>=0; i--)
        b.push_back(int(s[i] - '0'));
    BigInt c = a*b;
    for (auto i=c.crbegin(); i != c.crend(); i++)
        cout << *i;
    return 0;
}
