#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[10001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

long long MaxSub() {
    long long ans = -1e9, sum = 0;
    for (int i=1; i<=n; i++) {
        sum = sum + a[i];
        if (ans < sum)
            ans = sum;
        if (sum < 0)
            sum = 0;
    }
    return ans;
}

void Solve() {
    cin >> n;
    while (n != 0) {
        ReadData();
        long long ans = MaxSub();
        if (ans <= 0)
            cout << "Losing streak." << '\n';
        else
            cout << "The maximum winning streak is " << ans << "." << '\n';
        cin >> n;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}

