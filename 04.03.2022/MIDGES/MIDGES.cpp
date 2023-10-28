#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x[100002];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i];
}

ll Solution() {
    ll ans = 0;
    int Place = 0;
    sort(x+1, x+1+n, greater<int>());
    x[n+1] = 1e9+1;
    int i = 1;
    while (i <= n) {
        if (x[i] <= Place)
            break;
        int Changes = 1;
        ans += 1LL*(x[i] - Place);
        i++;
        while ((i <= n) && (x[i] == x[i-1])) {
            ans += 1LL*(x[i] - Place);
            Changes++;
            i++;
        }
        Place = Place + Changes;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MIDGES.INP", "r", stdin);
    freopen("MIDGES.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
