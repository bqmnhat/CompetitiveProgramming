#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n;
ll a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    ll ans = -1e18, tmp = 0;
    for (int i=1; i<=n; i++) {
        tmp += a[i];
        ans = max(ans, tmp);
        tmp = max(tmp, 0LL); // shortcut for checking if tmp < 0 => reset tmp = 0 because if there exist a sum x of elements after i in array a, tmp + x < x (because tmp < 0 so x will decrease)
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
