#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
stack <char> stk;
int ans;

int Solution() {
    int ans = s.length();
    stk.push('#');
    for (int i=0; i<s.length(); i++) {
        if (s[i] == stk.top()) {
            ans = ans - 2;
            stk.pop();
        }
        else
            stk.push(s[i]);
    }
    return ans;
}

int main()
{
    cin >> s;
    ans = Solution();
    if (ans == 0)
        cout << "0";
    else
        cout << ans;
    return 0;
}
