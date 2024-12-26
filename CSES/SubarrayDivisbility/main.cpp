#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n;
ll a[MaxN+5], cnt[MaxN+5], pref[MaxN+5], NMax = 1;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void FindNMax() {
    while (NMax < 1000000000000000)
        NMax = NMax*(1LL*n);
}

ll Solution() {
    cnt[0]++;
    for (int i=1; i<=n; i++) {
        pref[i] = (pref[i-1] + a[i] + NMax)%n;
        cnt[pref[i]]++;
    }
    ll ans = 0;
    for (int i=0; i<n; i++)
        ans = (ans + ((cnt[i]*(cnt[i]-1LL)) >> 1LL));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    FindNMax();
    cout << Solution();
    return 0;
}
