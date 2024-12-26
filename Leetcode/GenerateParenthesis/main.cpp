#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(int mask, int len) {
    vector<int> stk;
    while (len > 0) {
        int bit = (mask&1);
        if (bit == 1)
            stk.push_back(bit);
        else if ((!stk.empty()) && (stk.back() == 1) && (bit == 0))
            stk.pop_back();
        else
            return false;
        mask = (mask >> 1);
        len--;
    }
    if (!stk.empty())
        return false;
    return true;
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    n = n * 2;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (check(mask, n)) {
            string s = "";
            int len = n, tmp = mask;
            while (len > 0) {
                int bit = (tmp&1);
                if (bit == 0)
                    s = "(" + s;
                else
                    s = ")" + s;
                tmp = (tmp >> 1);
                len--;
            }
            //reverse(s.begin(), s.end());
            ans.push_back(s);
        }
    }
    return ans;
}

int main()
{
    vector<string> ans = generateParenthesis(3);
    for (string s: ans)
        cout << s << '\n';
    return 0;
}
