#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n;
ll l[MaxN+1], sum = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> l[i];
        sum += l[i];
    }
}

ll Solution() {
    sort(l+1, l+1+n);
    ll tmp = 0;
    int i = 1;
    while (tmp + l[i] <= sum/2) {
        tmp += l[i];
        i++;
    }
    ll tmp2 = sum - tmp;
    ll ans = tmp2 - tmp + 1LL;
    return ans;
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
