#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, tk[1001];

void Solve() {
    int ai, ans = 0;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        if (tk[ai] == 0)
            ans++;
        tk[ai]++;
    }
    cout << ans << '\n';
    bool exist = false;
    for (int i=0; i<=1000; i++) {
        if (tk[i] != 0) {
            if (!exist) {
                cout << i << " " << tk[i];
                exist = true;
            }
            else
                cout << '\n' << i << " " << tk[i];
        }
    }
}

int main()
{
    cin >> n;
    Solve();
    return 0;
}
