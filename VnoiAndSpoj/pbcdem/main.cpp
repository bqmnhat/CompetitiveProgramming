#include <iostream>
#include <bits/stdc++.h>
#define MaxN 4000
using namespace std;
typedef vector<int> BigInt;
int n;
BigInt dp[MaxN+5][105];

void trim(BigInt& a) {
    while ((!a.empty()) && (!a.back()))
        a.pop_back();
}

bool IsZero(const BigInt& x) {
    return ((x.empty()) || ((x.size() == 1) && (x[0] == 0)));
}

istream& operator >> (istream& stream, BigInt& x) {
    string s;
    stream >> s;
    int l = s.length();
    for (int i=l-1; i >= 0; i--)
        x.push_back(s[i] - '0');
    trim(x);
    return stream;
}

ostream& operator << (ostream& stream, const BigInt& x) {
    for (int i=x.size()-1; i>=0; i--)
        stream << x[i];
    return stream;
}

BigInt operator+(const BigInt& a, const BigInt& b) {
    BigInt ans;
    int i = 0, j = 0, r = 0;
    while ((i < a.size()) || (j < b.size())) {
        if (i < a.size())
            r += a[i++];
        if (j < b.size())
            r += b[j++];
        ans.push_back(r%10);
        r /= 10;
    }
    if (r > 0)
        ans.push_back(r);
    trim(ans);
    return ans;
}

BigInt operator-(const BigInt& a, const BigInt& b) {
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
    if (r > 0)
        ans.push_back(r);
    trim(ans);
    return ans;
}

BigInt Solution() {
    dp[1][1] = {1};
    dp[2][1] = {1};
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=100; j++) {
            dp[i][j] = dp[i][j] + dp[i][j-1];
            if (i > j)
                dp[i][j] = dp[i][j] + dp[i-j][j-1];
        }
    }
    return dp[n][100];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << Solution();
    return 0;
}
