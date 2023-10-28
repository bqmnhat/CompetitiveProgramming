#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200005
using namespace std;
typedef long long ll;
int n;
ll x[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i];
}

int Solution() {
    sort(x+1, x+1+n);
    int ans = 1;
    for (int i=2; i<=n; i++)
        if (x[i] != x[i-1])
            ans++;
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
