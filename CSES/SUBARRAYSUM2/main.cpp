#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long x, a[200001];
unordered_map<long long, int> m;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

long long CountSub() {
    long long ans = 0, sum = 0;
    for (int i=1; i<=n; i++) {
        sum = sum + a[i];
        if (sum == x)
            ans++;
        if (m.find(sum - x) != m.end()) {
            ans += m[sum-x];
        }
        m[sum] = m[sum] + 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    ReadData();
    cout << CountSub();
    return 0;
}
