#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
int a[MaxN+5], prefSum[MaxN+5];
unordered_map<int, int> lastPos;
vector<int> st;

int longestValidParentheses(string s) {
    int ans = 0, l = s.length();
    for (int i = 0; i < l; i++) {
        if (s[i] == '(')
            st.push_back(i);
        else {
            if ((!st.empty()) && (s[st.back()] == '('))
                st.pop_back();
            else
                st.push_back(i);
        }
    }
    if (st.empty())
        return l;
    int id1 = st.back(), id2 = 0;
    ans = l - id1 - 1;
    st.pop_back();
    while (!st.empty()) {
        id2 = st.back();
        st.pop_back();
        ans = max(ans, id1 - id2 - 1);
        id1 = id2;
    }
    ans = max(ans, id1 + 1);
    return ans;
}

int main()
{
    string s = "(()";
    cout << longestValidParentheses(s);
    return 0;
}
