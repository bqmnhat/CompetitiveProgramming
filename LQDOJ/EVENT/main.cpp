#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
typedef vector<int> BigInt;
int NumOfSticks[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, nSub1;
BigInt nSub2;

bool IsZero(const BigInt& x) {
    return ((x.empty()) || ((x.size() == 1) && (x[0] == 0)));
}

void trim(BigInt& x) {
    while ((!x.empty()) && (!x.back()))
        x.pop_back();
}

istream& operator >> (istream& stream, BigInt& x) {
    string s;
    stream >> s;
    int l = s.length();
    for (int i = l - 1; i>=0; i--)
        x.push_back(s[i] - '0');
    trim(x);
    return stream;
}

ostream& operator << (ostream& stream, const BigInt& x) {
    if (IsZero(x)) {
        stream << "0";
        return stream;
    }
    for (int i=x.size()-1; i>=0; i--)
        stream << x[i];
    return stream;
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

int CountSticksNeededFirstSub(int x) {
    int cnt = 0;
    while (x > 0) {
        cnt += NumOfSticks[x%10];
        x/=10;
    }
    return cnt;
}

int CountSticksNeededSecondSub(const BigInt& x) {
    int cnt = 0;
    for (int i=0; i<x.size(); i++)
        cnt += NumOfSticks[x[i]];
    return cnt;
}

int SolutionFirstSub() {
    int d = 0, tmp = nSub1;
    while (tmp > 0) {
        d++;
        tmp /= 10;
    }
    int Limit = 1;
    for (int i=1; i<=d; i++)
        Limit *= 10;
    Limit--;
    int SticksOfN = CountSticksNeededFirstSub(nSub1);
    for (int x = nSub1+1; x<=Limit; x++)
        if (CountSticksNeededFirstSub(x) == SticksOfN)
            return x;
    return -1;
}

BigInt SolutionSecondSub() {
    BigInt nSub2Origin = nSub2;
    vector<int> one = {1};
    int SticksOfN = CountSticksNeededSecondSub(nSub2), OriginLen = nSub2.size();
    for (int i=1; i<=10000; i++) {
        nSub2 = nSub2 + one;
        if (nSub2.size() > OriginLen)
            break;
        if (CountSticksNeededSecondSub(nSub2) == SticksOfN)
            return nSub2;
    }
    for (int i=0; i<nSub2Origin.size()-1; i++) {
        if (nSub2Origin[i] - nSub2Origin[i+1] == 1) {
            swap(nSub2Origin[i], nSub2Origin[i+1]);
            return nSub2Origin;
        }
    }
    return {-1};
}

void Solve() {
    if (nSub2.size() <= 5) {
        nSub1 = 0;
        for (int i=nSub2.size()-1; i>=0; i--)
            nSub1 = nSub1*10 + nSub2[i];
        int ans = SolutionFirstSub();
        if (ans == -1)
            cout << "NO SOLUTION";
        else
            cout << ans;
    }
    else {
        BigInt ans = SolutionSecondSub();
        vector<int> MinOne = {-1};
        if (ans == MinOne)
            cout << "NO SOLUTION";
        else
            cout << ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> nSub2;
    Solve();
    return 0;
}
