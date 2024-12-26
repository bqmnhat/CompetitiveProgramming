#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50000
using namespace std;
int n;
string s;

bool CheckPalindrome(string s) {
    int i = 0, j = n-1;
    while (i < j)  {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

bool CheckSame(string s) {
    bool ans = true;
    for (int i=0; i<n; i++)
        if (s[i] != s[0])
            ans = false;
    return ans;
}

int Solution() {
    if (CheckSame(s))
        return 0;
    if (CheckPalindrome(s))
        return n-1;
    return n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    cout << Solution();
    return 0;
}
