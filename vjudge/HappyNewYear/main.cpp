#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

void Solve() {
    vector<int> ans;
    while (n > 0LL) {
        if (n&1LL)
            ans.push_back(2);
        else
            ans.push_back(0);
        n >>= 1LL;
    }
    reverse(ans.begin(), ans.end());
    for (int x: ans)
        cout << x;
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
