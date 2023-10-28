#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n;
ll x, p[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> p[i];
}

int Solution() {
    sort(p+1, p+1+n);
    int i=1, j=n, ans = 0;
    while (i < j) {
        if (p[i] + p[j] <= x) {
            ans++;
            i++;
            j--;
        }
        else {
            j--;
            ans++;
        }
    }
    ans += j - i + 1;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    ReadData();
    cout << Solution();
    return 0;
}
