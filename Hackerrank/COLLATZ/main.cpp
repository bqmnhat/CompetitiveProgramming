#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, cnt[501], a[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        cnt[a[i]]++;
        if (((k - (a[i]*a[i])) >= 0) && ((k - (a[i]*a[i])) <= 500))
            ans = ans + (1LL*cnt[k - (a[i]*a[i])]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    cout << Solution();
    return 0;
}
