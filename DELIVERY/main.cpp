#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, m, small[501], large[1001];

void ReadData() {
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> small[i];
    cin >> m;
    for (int j=1; j<=m; j++)
        cin >> large[j];
}

int Solution() {
    int st = 1, TimeSmall = 0, TimeLarge = 0;
    while (TimeSmall + small[st] <= t) {
        TimeSmall += small[st];
        st++;
    }
    for (int i=st; i<=n; i++) {
        m++;
        large[m] = small[i];
    }
    sort(large + 1, large + 1 + m);
    int i = 1;
    while (TimeLarge + large[i] <= t) {
        TimeLarge += large[i];
        i++;
    }
    i--;
    st--;
    int ans = i + st;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DELIVERY.INP", "r", stdin);
    freopen("DELIVERY.OUT", "w", stdout);
    cin >> t;
    ReadData();
    cout << Solution();
    return 0;
}
