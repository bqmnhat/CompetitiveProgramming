#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, d;
pair<ll, ll> a[100001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].first >> a[i]. second;
}

ll MaxFriendship() {
    sort(a+1, a+1+n);
    int l = 1 , r = 1;
    ll Sum = a[1].second, ans = 0;
    while ((l <= n) && (r <= n)) {
        if (Sum > ans)
            ans = Sum;
        if ((a[r+1].first - a[l].first < d) || (l > r)) {
            r++;
            Sum += a[r].second;
        }
        else {
            Sum = Sum - a[l].second;
            l++;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> d;
    ReadData();
    cout << MaxFriendship();
    return 0;
}
