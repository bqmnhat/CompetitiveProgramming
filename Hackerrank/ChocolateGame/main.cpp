#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string ans;

void Solve() {
    while (n > 0) {
        if (n%2 == 0) {
            ans = ans + 'T';
            n >>= 1LL;
        }
        else {
            ans = ans + 'D';
            n--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
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
