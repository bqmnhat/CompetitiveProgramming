#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int t, n, a[MaxN+1], SpTabMax[MaxN+2][20], SpTabMin[MaxN+2][20], log_2[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        SpTabMax[i][0] = SpTabMin[i][0] = a[i];
    }
}

void MakeLog2() {
    for (int i=2; i<=MaxN; i++)
        log_2[i] = log_2[i/2] + 1;
}

void MakeSparseTables() {
    int step;
    for (int j=1; (1 << j) <= n; j++) {
        step = (1 << (j - 1));
        for (int i=1; i + 2*step <= n+1; i++) {
            SpTabMax[i][j] = max(SpTabMax[i][j-1], SpTabMax[i + step][j-1]);
            SpTabMin[i][j] = min(SpTabMin[i][j-1], SpTabMin[i + step][j-1]);
        }
    }
}

int GetMax(int l, int r) {
    int k = log_2[r-l+1];
    return max(SpTabMax[l][k], SpTabMax[r - (1 << k) + 1][k]);
}

int GetMin(int l, int r) {
    int k = log_2[r-l+1];
    return min(SpTabMin[l][k], SpTabMin[r - (1 << k) + 1][k]);
}

void SolveTestCase() {
    MakeSparseTables();
    for (int i = 1; i+2 <= n; i++) {
        int lo = i+1, hi = n-1, mid;
        while (lo <= hi) {
            mid = (lo + hi)/2;
            if ((GetMax(1, i) < GetMax(mid+1, n)) || (GetMax(1, i) < GetMin(i+1, mid)))
                lo = mid + 1;
            else if ((GetMax(1, i) > GetMax(mid+1, n)) || (GetMax(1, i) > GetMin(i+1, mid)))
                hi = mid - 1;
            else {
                cout << "YES\n" << i << ' ' << mid - i << ' ' << n-mid << '\n';
                return;
            }
        }
    }
    cout << "NO\n";
}

void Solve() {
    MakeLog2();
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
