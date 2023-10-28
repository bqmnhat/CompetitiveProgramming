#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> BigInt;
BigInt n, Pow10[1001], FromOneToTenths[1001];
// Input Output
void trim(BigInt& a) {
    while (!a.empty() && !a.back())
        a.pop_back();
}

istream& operator>>(istream& stream, BigInt& x) {
    string s;
    x.clear();
    stream >> s;
    for (int i=s.length()-1; i>=0; i--)
        x.push_back(s[i] - '0');
    trim(x);
    return stream;
}

ostream& operator<<(ostream& stream, const BigInt& x) {
    for (int i=x.size()-1; i>=0; i--)
        stream << x[i];
    return stream;
}

bool IsZero(const BigInt& x) {
    return ((x.empty()) || (x[x.size() - 1] == 0));
}
// Sum of 2 Big Numbers
BigInt operator + (const BigInt& a, const BigInt& b) {
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
    trim(ans);
    if (IsZero(ans))
        return {0};
    return ans;
}
// Subtraction of 2 Big Numbers
BigInt operator - (const BigInt& a, const BigInt& b) {
    BigInt ans;
    int i = 0, j = 0, r = 0;
    while ((i < a.size()) || (j < b.size())) {
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
    trim(ans);
    return ans;
}
// Multiplication of 2 Big Numbers
BigInt operator * (const BigInt& a, int b) // Multiplication of 1 Big Number and 1 integer
{
    if ((IsZero(a)) || (b == 0))
        return {0};
    BigInt ans;
    int r = 0;
    for (int i = 0; i < a.size(); ++i) {
        r = r + a[i]*b;
        ans.push_back(r%10);
        r = r/10;
    }
    if (r > 0)
        ans.push_back(r);
    trim(ans);
    return ans;
}
BigInt pow10(BigInt a, int n) { //ham mu 10
    BigInt ans(a.size()+n, 0);
    for (int i = 0, j = n; i < a.size(); ++i, ++j)
        ans[j] = a[i];
    trim(ans);
    return ans;
}
BigInt operator * (const BigInt& a, const BigInt& b) // Multiplication of 2 BigInts
{
    BigInt ans;
    for (int i = 0; i < b.size(); ++i) {
        BigInt tmp = a*b[i]; // Use Multiplication operator of 1 BigInt and 1 integer
        tmp = pow10(tmp, i);
        ans = ans + tmp;
    }
    trim(ans);
    return ans;
}

void MakePow10() {
    Pow10[0] = {1};
    for (int i=1; i<=1000; i++)
        Pow10[i] = Pow10[i-1]*10;
}

void MakeFromOneToTenths() {
    FromOneToTenths[0] = {1};
    FromOneToTenths[1] = {5, 4};
    for (int i=2; i<=1000; i++)
        FromOneToTenths[i] = FromOneToTenths[i-1]*10 + Pow10[i-1]*45;
}

BigInt Sum(const BigInt& x) {
    if (IsZero(x))
        return {0};
    if (x.size() == 1) {
        int SumDig = 0;
        for (int i=1; i<=x[0]; i++)
            SumDig+=i;
        vector<int> res;
        res.clear();
        while (SumDig > 0) {
            res.push_back(SumDig%10);
            SumDig/=10;
        }
        return res;
    }
    int msd = x[x.size()-1];
    BigInt tmp;
    tmp.clear();
    for (int i=0; i<x.size()-1; i++)
        tmp.push_back(x[i]);
    trim(tmp);
    int d = x.size();
    vector<int> one = {1};
    return (FromOneToTenths[d-1]*msd + Pow10[d-1]*(msd*(msd-1)/2) + (tmp + one)*msd + Sum(tmp));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakePow10();
    MakeFromOneToTenths();
    cin >> n;
    cout << Sum(n);
    return 0;
}
