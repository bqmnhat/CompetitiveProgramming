#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, h[1000001], j[1000001];
pii JumpBoard[1000001];
stack <pii> stk;

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> h[i];
}

void MakeJumpBoard() {
    for (int i=0; i<n; i++)
        JumpBoard[i].first = JumpBoard[i].second = -1;
    for (int i=n-1; i>=0; i--) {
        if (stk.empty()) {
            stk.push(pii(h[i], i));
            continue;
        }
        while ((!stk.empty()) && (stk.top().first <= h[i]))
            stk.pop();
        if (!stk.empty()) {
            JumpBoard[i].first = stk.top().first;
            JumpBoard[i].second = stk.top().second;
        }
        stk.push(pii(h[i], i));
    }
}

void Solve() {
    int jsteps;
    for (int i=0; i<n; i++) {
        cin >> jsteps;
        int j = 0, ans = h[i], Id = i;
        while ((j < jsteps) && (Id != -1)) {
            ans = JumpBoard[Id].first;
            Id = JumpBoard[Id].second;
            j++;
        }
        cout << ans << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FROGS.INP", "r", stdin);
    freopen("FROGS.OUT", "w", stdout);
    cin >> n;
    ReadData();
    MakeJumpBoard();
    Solve();
    return 0;
}
