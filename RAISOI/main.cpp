#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1001], n;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll ClkWise(ll i) {
    ll k = a[i]%n;
    ll Tar = i + k + 1;
    if (Tar > n)
        Tar = Tar%n;
    if (Tar == i)
        return (a[i]/n);
    else
        return (a[Tar] + a[i]/n);
}

ll AntiClkWise(ll i) {
    ll k = a[i]%n;
    ll Tar = i - k - 1;
    if (Tar < 1)
        Tar = Tar+n;
    if (Tar == i)
        return (a[i]/n);
    else
        return (a[Tar] + a[i]/n);
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=n; i++)
        ans = max(ans, max(ClkWise(i), AntiClkWise(i)));
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
