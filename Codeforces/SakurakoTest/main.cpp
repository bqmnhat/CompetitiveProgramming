#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int t, n, q, x, prefCount[MaxN+5], res[MaxN+5];

void ReadData() {
    for (int i = 1; i <= 2*n; i++)
        prefCount[i] = 0;
    int ai;
    for (int i = 1; i <= n; i++) {
        cin >> ai;
        prefCount[ai]++;
    }
}

void makePrefCount() {
    for (int i = 1; i <= 2*n; i++)
        prefCount[i] += prefCount[i-1];
}

void preCalSolution() {
    for (int x = 1; x <= n; x++) {
        int lo = 0, hi = x, ans = 0;
        while (lo <= hi) {
            int med = ((lo + hi) >> 1);
            int cnt = prefCount[med];
            for (int k = 1; k*x <= n; k++)
                cnt += prefCount[k*x + med] - prefCount[k*x - 1];
            int threshold = (n/2 + 1);
            if (cnt >= threshold) {
                ans = med;
                hi = med - 1;
            } else
                lo = med + 1;
        }
        res[x] = ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        ReadData();
        makePrefCount();
        preCalSolution();
        while (q--) {
            cin >> x;
            cout << res[x] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
