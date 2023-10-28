#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int k, n, a[MaxN+5];
map<int, int> check;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    ll i = 1, j = 1;
    ll ans = 0;
    check[a[1]]++;
    while (j < n) {
        if (check.size() > k) {
            ans += j-i;
            check[a[i]]--;
            if (check[a[i]] <= 0)
                check.erase(a[i]);
            i++;
        }
        else {
            j++;
            check[a[j]]++;
        }
    }
    while (i <= n) {
        if (check.size() > k)
            ans += n - i;
        else
            ans += n - i + 1;
        check[a[i]]--;
        if (check[a[i]] <= 0)
            check.erase(a[i]);
        i++;
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
