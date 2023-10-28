#include <iostream>
#include <bits/stdc++.h>
#define MaxN 16
using namespace std;
typedef long long ll;
ll c, w[MaxN+5];
int n;

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> w[i];
}

ll SumOfMask(int mask) {
    ll ans = 0;
    for (int i=0; i<n; i++)
        if (mask & (1 << i))
            ans += w[i];
    return ans;
}

ll Solution() {
    ll res = 0;
    for (int mask=0; mask < (1 << n); mask++) {
        ll MaskSum = SumOfMask(mask);
        if (MaskSum <= c)
            res = max(res, MaskSum);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n;
    ReadData();
    cout << Solution();
    return 0;
}
