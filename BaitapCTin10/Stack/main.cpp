#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
stack <long long> st;

void Solve() {
    int cmd;
    long long a;
    for (int i=1; i<=n; i++) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> a;
            st.push(a);
        }
        else if (cmd == 2) {
            if (!st.empty())
                cout << st.top() << '\n';
            else
                cout << "-1" << '\n';
        }
        else if (!st.empty())
            st.pop();
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
