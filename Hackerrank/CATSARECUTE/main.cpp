#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int n;
ll a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int CntFacs(ll x, ll Facs) {
    int ans = 0;
    while ((x > 0) && (x%Facs == 0)) {
        ans++;
        x = x/Facs;
    }
    return ans;
}

int Solution() {
    int cntFives = 0, cntTwos = 0;
    for (int i=1; i<=n; i++) {
        cntFives += CntFacs(a[i], 5);
        cntTwos += CntFacs(a[i], 2);
    }
    return min(cntFives, cntTwos);
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
