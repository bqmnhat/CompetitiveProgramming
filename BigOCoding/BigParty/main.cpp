#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,r,c;
long long B, m[1001], s[1001], p[1001];

void ReadData() {
    for (int i=1; i<=c; i++)
        cin >> m[i] >> s[i] >> p[i];
}

bool CheckTime(long long Time) {
    long long items[1001];
    for (int i=1; i<=c; i++)
        items[i] = max(0LL, min( m[i], ((Time - p[i])/s[i]) ));
    long long Cnt = 0;
    sort(items + 1, items + 1 + c, greater<long long>());
    for (int i=1; i<=r; i++)
        Cnt += items[i];
    return (Cnt >= B);
}

long long MaxItems() {
    long long lo = 2, hi = (long long)2e18, ans = 0;
    while (lo < hi) {
        long long Time = (lo + hi)/2;
        if (CheckTime(Time)) {
            ans = Time;
            hi = Time;
        }
        else
            lo = Time + 1LL;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> r >> B >> c;
        ReadData();
        cout << "Case #" << i << ": " << MaxItems() << '\n';
    }
}

int main()
{
    cin >> t;
    Solve();
    return 0;
}
