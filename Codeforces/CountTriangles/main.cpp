#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
using namespace std;
typedef long long ll;
ll A, B, C, D;

ll Solution() {
    ll ans = 0, y = B, z = C;
    while (z <= D) {
        ll tmpx = z - y + 1;
        if (tmpx > B) {
            y++;
            if (y > C) {
                y--;
                z++;
            }
            continue;
        }
        if (tmpx < A) {
            tmpx = A;
        }
        ll incAmount = 0;
        if (C - y + 1LL >= (B - A + 1LL) - (B - tmpx + 1LL) + 1LL) {
            incAmount += ((((B - tmpx + 1LL) + (B - A + 1LL)) * ((B - A + 1LL) - (B - tmpx + 1LL) + 1LL)) >> 1LL);
            incAmount += (B - A + 1LL) * (C - y + 1LL - ((B - A + 1LL) - (B - tmpx + 1LL) + 1LL));
        } else {
            incAmount += ((((B - tmpx + 1LL) + (B - tmpx + 1LL + C - y)) * (C - y + 1LL)) >> 1LL);
        }
        ans += incAmount;
        z++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B >> C >> D;
    cout << Solution();
    return 0;
}
