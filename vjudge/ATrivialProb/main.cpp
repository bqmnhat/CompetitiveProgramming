#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m;

void Solve() {
    int i = 5, cnt = 0;
    vector<int> ans;
    ans.clear();
    while (true) {
        int tmp = i;
        while (tmp%5 == 0) {
            cnt++;
            tmp /= 5;
        }
        if (cnt == m)
            ans.push_back(i);
        if (cnt > m)
            break;
        i++;
    }
    cout << ans.size() << '\n';
    if (ans.size() == 0)
        return;
    for (auto x: ans)
        cout << x << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    Solve();
    return 0;
}
