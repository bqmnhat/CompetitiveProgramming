#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
const ll Mod = 123456789;
string s;
int t;
stack<ll> stk;

ll Solution() {
    if ((s[0] != '-') && (s[0] != '+'))
        s = "+" + s;
    int i = 0, l = s.length(), Sign = 1;
    while (i < l) {
        Sign = 1;
        if (s[i] == '-') {
            Sign = -1;
            i++;
        }
        else if (s[i] == '+') {
            Sign = 1;
            i++;
        }
        else if (s[i] == '*') {
            Sign = 2;
            i++;
        }
        ll CurNum = 0;
        while ((i < l) && (s[i] >= '0') && (s[i] <= '9')) {
            CurNum = (((CurNum*10)%Mod) + (s[i] - '0'))%Mod;
            i++;
        }
        if (Sign == 1)
            stk.push(CurNum);
        else if (Sign == -1)
            stk.push((Mod - CurNum)%Mod);
        else {
            ll tmp = stk.top();
            stk.pop();
            tmp = (tmp*CurNum)%Mod;
            stk.push(tmp);
        }
    }
    ll ans = 0;
    while (!stk.empty()) {
        ans = (ans + stk.top())%Mod;
        stk.pop();
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
