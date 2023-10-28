#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[200001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    ll l, r = 1;
    ll cnt = 0;
    sort(a+1, a+1+n);
    for (l = 1; l<=n; l++) {
        while ((a[r] - a[l] <= 5) && (r <= n))
            r++;
        cnt = max(cnt, r-l);
    }
    cnt = max(cnt, r-l);
    return cnt;
}

int main()
{
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
