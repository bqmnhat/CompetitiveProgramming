#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200001], x;
map <long long, long long> m;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

long long Solution() {
    long long sum = 0, ans = 0;
    for (int i=1; i<=n; i++) {
        sum += a[i];
        if (sum == x)
            ans++;
        if (m.find(sum - x) != m.end()) {
            ans += m[sum - x];
        }
        m[sum]++;
    }
    return ans;
}

int main()
{
    cin >> n >> x;
    ReadData();
    cout << Solution();
    return 0;
}
