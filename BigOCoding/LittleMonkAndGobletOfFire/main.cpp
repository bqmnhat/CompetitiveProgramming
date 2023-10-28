#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int Q;
queue <int> q[5];

void Solve() {
    string cmd;
    for (int i=1; i<=Q; i++) {
        cin >> cmd;
        if (cmd == "E") {
            int x, y;
            cin >> x >> y;
            if (q[x].empty())
                q[0].push(x);
            q[x].push(y);
        }
        else {
            cout << q[0].front() << ' ' << q[q[0].front()].front() << '\n';
            q[q[0].front()].pop();
            if (q[q[0].front()].empty())
                q[0].pop();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Q;
    Solve();
    return 0;
}
