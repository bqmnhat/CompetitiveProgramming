#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[1000001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    ll ans = 0, sum = 0;
    for (int i=1; i<=n; i++) {
        sum += a[i];
        ans = max(ans, sum);
        if (sum < 0)
            sum = 0;
    }
    return ans;
}

void Solve() {
    while (cin >> n) {
        if (n == 0)
            break;
        ReadData();
        ll MaxMoney = Solution();
        if (MaxMoney <= 0)
            cout << "Losing streak.\n";
        else
            cout << "The maximum winning streak is " << MaxMoney << ".\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
