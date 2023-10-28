#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Fac[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}, y;

void Solve() {
    vector<int> ans;
    if (y == 1) {
        cout << "0";
        return;
    }
    while (y > 0) {
        int tmp = 0;
        while ((tmp <= 8) && (Fac[tmp+1] <= y))
            tmp++;
        ans.push_back(tmp);
        y -= Fac[tmp];
    }
    sort(ans.begin(), ans.end());
    for (int x: ans)
        cout << x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> y;
    Solve();
    return 0;
}
