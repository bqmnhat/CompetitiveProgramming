#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int GivenAns;
stack<int> stk;

int Rule1() {
    int l = s.length(), i = 0, MAns;
    while (i < l) {
        if (i%2 == 0)
            stk.push(int(s[i] - '0'));
        else if (s[i] == '*') {
            int a1 = stk.top(), a2 = (s[i+1] - '0');
            stk.pop();
            int mulans = a1*a2;
            stk.push(mulans);
            i++;
        }
        i++;
    }
    MAns = 0;
    while (!stk.empty()) {
        MAns += stk.top();
        stk.pop();
    }
    return MAns;
}

int Rule2() {
    int l = s.length(), LAns = s[0] - '0', i = 1;
    while (i < l) {
        if (s[i] == '+')
            LAns += (s[i+1] - '0');
        else
            LAns = LAns * (s[i+1] - '0');
        i+=2;
    }
    return LAns;
}

void Solve() {
    int MAns = Rule1(), LAns = Rule2();
    if ((MAns == GivenAns) && (LAns == GivenAns))
        cout <<'U';
    else if (MAns == GivenAns)
        cout << 'M';
    else if (LAns == GivenAns)
        cout << 'L';
    else
        cout << 'I';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> GivenAns;
    Solve();
    return 0;
}
