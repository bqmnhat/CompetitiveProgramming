#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int k, n;
ll a[MaxN+5], MaxA = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        MaxA = max(MaxA, a[i]);
    }
}

bool Check(ll x) {
    vector<ll> SubseqOdd, SubseqEven;
    SubseqOdd.clear();
    SubseqEven.clear();
    for (int i=1; i<=n; i++) {
        int lOdd = SubseqOdd.size(), lEven = SubseqEven.size();
        if (lOdd % 2 == 0) {
            if (a[i] <= x)
                SubseqOdd.push_back(a[i]);
        }
        else
            SubseqOdd.push_back(a[i]);
        if (lEven%2 == 1) {
            if (a[i] <= x)
                SubseqEven.push_back(a[i]);
        }
        else
            SubseqEven.push_back(a[i]);
    }
    return ((SubseqOdd.size() >= k) || (SubseqEven.size() >= k));
}


ll Solution() {
    ll lo = 1, hi = MaxA, ans = -1;
    while (lo <= hi) {
        ll mid = (lo + hi)/2;
        if (Check(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
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
