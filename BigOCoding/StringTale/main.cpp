#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
string s1, s2;

vector<int> MakeZFunction(string s)  {
    int n = s.length();
    vector<int> z(n);
    z[0] = n;
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
        if (i <= r)
            z[i] = min(z[i-l], r-i+1);
        while ((i + z[i] < n) && (s[z[i]] == s[i + z[i]]))
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int Solution() {
    int lens1 = s1.length(), lens2 = s2.length();
    string tmp = s2 + char(3) + s1;
    int tmplen = tmp.length();
    vector<int> z = MakeZFunction(tmp);
    for (int i=lens2+1; i<tmplen; i++)
        if (i + z[i] >= tmplen)
            return (tmplen - i);
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s1 >> s2;
    cout << Solution();
    return 0;
}
