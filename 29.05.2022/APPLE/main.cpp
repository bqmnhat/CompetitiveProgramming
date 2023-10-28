#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m, n, a, t;

int Solution() {
    int ans = 0, head = 1, tail = m;
    for (int i=1; i<=t; i++) {
        int ai;
        cin >> ai;
        if ((head <= ai) && (tail >= ai))
            continue;
        int MinDist = min(abs(ai - head), abs(ai - tail));
        ans += MinDist;
        if (ai < head) {
            head = head - MinDist;
            tail = tail - MinDist;
        }
        else if (ai > tail) {
            head = head + MinDist;
            tail = tail + MinDist;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("APPLES.INP", "r", stdin);
    freopen("APPLES.OUT", "w", stdout);
    cin >> n >> m >> t;
    cout << Solution();
    return 0;
}
