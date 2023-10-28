#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 100000
typedef long long ll;
int t, n;
ll a[MaxN+1], cnt[31];

void InitCnt() {
    for (int i=0; i<=30; i++)
        cnt[i] = 0;
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

ll CalPi(ll val) {
    ll ans = 0;
    int i = -1;
    while (val > 0) {
        i++;
        if (val%2 == 1)
            ans = i;
        val = val/2;
    }
    return ans;
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        cnt[CalPi(a[i])]++;
    }
    for (int i=0; i<=30; i++) {
        ans += (cnt[i]*(cnt[i] - 1))/2;
    }
    return ans;
}

int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        InitCnt();
        cin >> n;
        ReadData();
        cout << Solution() << '\n';
    }
    return 0;
}
