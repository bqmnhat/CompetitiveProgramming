#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
bool mark[10001];

void Solve() {
    stack<int> stk;
    int x, pre = 0;
    for (int i=1; i<=n; i++) {
        cin >> x;
        mark[x] = true;
        if (x > pre) {
            cout << x << ' ';
            while (++pre < x)
                stk.push(pre);
        }
        while ((!stk.empty()) && (mark[stk.top()])) {
            cout << stk.top() << ' ';
            stk.pop();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Solve();
    return 0;
}
