#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> BigNum;
ll p, q;
// Sum of 2 Big Numbers
BigNum operator + (BigNum a, BigNum b) {
    BigNum ans;
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
BigNum operator - (BigNum a, BigNum b) {
    BigNum ans;
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
BigNum operator * (BigNum a, int b) // Multiplication of 1 Big Number and 1 integer
{
    BigNum ans;
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
BigNum pow10(BigNum a, int n) { //ham mu 10
    BigNum ans(a.size()+n, 0);
    for (int i = 0, j = n; i < a.size(); ++i, ++j)
        ans[j] = a[i];
    return ans;
}
BigNum operator * (BigNum a, BigNum b) // Multiplication of 2 BigNums
{
    BigNum ans;
    for (int i = 0; i < b.size(); ++i) {
        BigNum tmp = a*b[i]; // Use Multiplication operator of 1 BigNum and 1 integer
        tmp = pow10(tmp, i);
        ans = ans + tmp;
    }
    return ans;
}

void PrintAns(BigNum a) {
    for (int i=a.size()-1; i>=0; i--)
        cout << a[i];
}

BigNum Solution(ll x, ll y) {
    if (x == y)
        return {0};
    if (x > y) {
        BigNum tmp = {2};
        return ((Solution(x-y, y)*2) + tmp);
    }
    BigNum tmp = {1};
    return ((Solution(x, y-x)*2) + tmp);
}

void Solve() {
    while (cin >> p >> q) {
        PrintAns(Solution(p, q));
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
