#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> BigNum;
int t, n;

BigNum StringToBigNum(string s) {
    int l = s.length() - 1;
    BigNum ans;
    ans.clear();
    for (int i=l; i>=0; i--)
        ans.push_back(s[i] - '0');
    return ans;
}

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

void Solve() {
    string s;
    BigNum a, b, tmp;
    for (int i=1; i<=t; i++) {
        cin >> n >> s;
        a = StringToBigNum(s);
        tmp.clear();
        if (a[n-1] == 9)
            for (int i=0; i<=n; i++)
                tmp.push_back(1);
        else
            for (int i=0; i<n; i++)
                tmp.push_back(9);
        b = tmp - a;
        for (int i=n-1; i>=0; i--)
            cout << b[i];
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
