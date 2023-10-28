#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[2000001], CntMask[1024];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int MaskOfx(int x) {
    int ans = 0;
    if (x == 0)
        ans = 1;
    while (x > 0) {
        int tmp = x%10;
        x = x/10;
        ans = (ans | (1 << tmp));
    }
    return ans;
}

ll Solution() {
    for (int i=1; i<=n; i++)
        CntMask[MaskOfx(a[i])]++;
    ll ans = 0;
    for (int i=1; i<=1023; i++) {
        ans += ((1LL*CntMask[i]*(CntMask[i]-1LL)))/2;
        for (int j=i+1; j<=1023; j++)
            if ((i & j) > 0)
                ans += (1LL*CntMask[i]*CntMask[j]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("RELATIVES.INP", "r", stdin);
    freopen("RELATIVES.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
