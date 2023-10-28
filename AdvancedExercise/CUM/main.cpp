#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> stk, fst,lst;
string s;

int Equations() {
    int ans = 0, l = s.length();
    for (int i=1; i<=l; i++) {
        if (s[i] == '(')
            stk.push_back(i);
        if (s[i] == ')') {
            if (stk.empty() == false) {
                fst.push_back(stk.back());
                lst.push_back(i);
                ans = ans + 1;
                stk.pop_back();
            }
            else
                return -1;
        }
    }
    return ans;
}

void Print() {
    int m = fst.size();
    for (int i=0; i<m; i++) {
        cout << s.substr(fst.at(i), lst.at(i)-fst.at(i)+1)<< endl;
    }
}

int main()
{
    freopen("CUM.INP", "r", stdin);
    freopen("CUM.OUT", "w", stdout);
    cin >> s;
    cout << Equations() << endl;
    Print();
    return 0;
}
