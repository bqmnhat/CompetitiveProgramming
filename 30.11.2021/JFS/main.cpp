#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, a[1000001], b[1000001];
stack<pii> stk;

void ReadData() {
    n = 0;
    int i = 1;
    while (cin >> a[i])
        i++;
    n = i-1;
}

void Solve() {
    for (int i=1; i<=n; i++)
        b[i] = -1;
    for (int i=n; i>=1; i--) {
        if (stk.empty()) {
            stk.push(pii(a[i], i));
            continue;
        }
        while ((!stk.empty()) && (stk.top().first <= a[i]))
            stk.pop();
        if (!stk.empty())
            b[i] = stk.top().second;
        stk.push(pii(a[i], i));
    }
    for (int i=1; i<=n; i++)
        cout << b[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("JFS.INP", "r", stdin);
    freopen("JFS.OUT", "w", stdout);
    ReadData();
    Solve();
    return 0;
}
