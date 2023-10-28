#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<ll> stk;

ll Solution() {
    string s;
    bool ExistCriteria = false;
    while (cin >> s) {
        if (s == "S")
            continue;
        if (s == "ENDPROGRAM")
            break;
        if (s == "IF") {
            ExistCriteria = true;
            stk.push(-1);
            stk.push(1);
        }
        else if (s == "ELSE") {
            stk.push(-2);
            stk.push(1);
        }
        else {
            ll BranchVal[2] = {1, 1};
            int idx = 0;
            while (!stk.empty()) {
                ll tmp = stk.top();
                stk.pop();
                if (tmp == -1)
                    break;
                else if (tmp == -2)
                    idx++;
                else
                    BranchVal[idx] *= tmp;
            }
            ll ThisBranchVal = BranchVal[0] + BranchVal[1];
            if (!stk.empty()) {
                ll PrevBranchVal = stk.top();
                stk.pop();
                ThisBranchVal *= PrevBranchVal;
            }
            stk.push(ThisBranchVal);
        }
    }
    if (!ExistCriteria)
        return 1;
    return stk.top();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << Solution();
    return 0;
}
