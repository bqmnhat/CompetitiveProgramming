#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n,a[10001];
bool mark[10001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void InitMark() {
    for (int i=1; i<=n; i++)
        mark[i] = false;
}

void SolveTestCase() {
    stack<int> stk;
    int pre = 0;
    for (int i=1; i<=n; i++) {
        mark[a[i]] = true;
        if (a[i] > pre) {
            cout << a[i] << ' ';
            while (++pre < a[i])
                stk.push(pre);
        }
        while ((!stk.empty()) && (mark[stk.top()])) {
            cout << stk.top() << ' ';
            stk.pop();
        }
    }
    if (!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        InitMark();
        SolveTestCase();
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
