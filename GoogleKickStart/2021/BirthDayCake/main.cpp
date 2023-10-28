#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long t, r, c, k, r1, c1, r2, c2;

long long EdgetoCake() {
    long long ans = 1e9;
    if (abs(1 - r1) < ans) {
        ans = abs(1 - r1);
    }
    if (abs(r - r2) < ans) {
        ans = abs(r - r2);
    }
    if (abs(1 - c1) < ans) {
        ans = abs(1 - c1);
    }
    if (abs(c - c2) < ans) {
        ans = abs(c - c2);
    }
    return ans;
}

long long CutAround() {
    long long ans = 0;
    long long tmp1 = ((abs(c2 - c1)-1)/k) + 1;
    long long tmp2 = ((abs(r2 - r1)-1)/k) + 1;
    if (c1 != 1) {
        ans += tmp1;
    }
    if (c2 <=  c) {
        ans += tmp1;
    }
    if (r1 != 1) {
        ans += tmp2;
    }
    if (r2 <= r) {
        ans += tmp2;
    }
    return ans;
}

long long Solution() {
    long long ans;
    ans = EdgetoCake()-1;
    if (ans < 0)
        ans = 0;
    else {
        ans = (ans/k) + 1;
    }
    r2 = r2 + 1;
    c2 = c2 + 1;
    ans += CutAround();
    return ans;
}

int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> r >> c >> k >> r1 >> c1 >> r2 >> c2;
        cout << "Case #" << i << ": " << Solution();
    }
    return 0;
}
