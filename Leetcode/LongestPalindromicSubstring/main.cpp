#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;

bool CheckPalin(int len, const string& s, string& ans) {
    int l = s.length();
    for (int i = 0; i < l; i++) {
        int tmpI = i, tmpJ = i + len - 1;
        while ((tmpI <= tmpJ) && (s[tmpI] == s[tmpJ])) {
            tmpI++;
            tmpJ--;
        }
        if (tmpI > tmpJ) {
            ans = "";
            for (int t = i; t <= i + len - 1; t++)
                ans = ans + s[t];
            return true;
        }
    }
    return false;
}

string longestPalindrome(string s) {
    string ans = "";
    int lo = 1, hi = s.length();
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        if (CheckPalin(mid, s, ans))
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}
