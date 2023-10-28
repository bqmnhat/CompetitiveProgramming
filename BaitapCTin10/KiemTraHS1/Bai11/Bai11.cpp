#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> cstk;
int l;

int OperatorPriority(char c)
{
    if ((c == '-') || (c == '+'))
        return 1;
    else if ((c == '*') || (c == '/'))
        return 2;
    else if (c == '^')
        return 3;
    return 0;
}

bool IsAlphabet(char c) {
    return (((c <= 'Z') && (c >= 'A')) || ((c <= 'z') && (c >= 'a')));
}

bool IsDigit(char c) {
    return ((c <= '9') && (c >= '0'));
}

bool IsOperator(char c)
{
    return (!IsAlphabet(c) && !IsDigit(c));
}

string Postfix()
{
    string ans;
    for (int i = 0; i < l; i++) {
        if ((IsAlphabet(s[i])) || (IsDigit(s[i])))
            ans = ans + s[i];
        else if (s[i] == '(')
            cstk.push(s[i]);
        else if (s[i] == ')') {
            while (cstk.top() != '(') {
                ans = ans + cstk.top();
                cstk.pop();
            }
            cstk.pop();
        }
        else if (IsOperator(cstk.top())) {
            if(s[i] == '^'){
                while (OperatorPriority(s[i]) <= OperatorPriority(cstk.top())) {
                    ans = ans + cstk.top();
                    cstk.pop();
                }
            }
            else
            {
                while (OperatorPriority(s[i]) < OperatorPriority(cstk.top())) {
                    ans = ans + cstk.top();
                    cstk.pop();
                }
            }
            cstk.push(s[i]);
        }
    }
    return ans;
}

string Prefix()
{
    reverse(s.begin(), s.end());
    for (int i = 0; i < l; i++) {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }
    string ans = Postfix();
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    freopen("Bai11.INP", "r", stdin);
    freopen("Bai11.OUT", "w", stdout);
    getline(cin,s);
    s = '(' + s + ')';
    l = s.length();
    cout << Prefix();
    return 0;
}
