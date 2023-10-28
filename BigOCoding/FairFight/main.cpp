#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t, n, k, c[MaxN+1], d[MaxN+1], log_2[MaxN+1], SpTabMaxC[MaxN+2][21], SpTabMaxD[MaxN+2][21];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> c[i];
        SpTabMaxC[i][0] = c[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> d[i];
        SpTabMaxD[i][0] = d[i];
    }
}

void MakeLog2() {
    for (int i=2; i<=MaxN; i++)
        log_2[i] = log_2[i/2]+1;
}

void MakeSparseTables() {
    int step;
    for (int j = 1; (1 << j) <= n; j++) {
        step = (1 << (j-1));
        for (int i=1; i + 2*step <= n+1; i++) {
            SpTabMaxC[i][j] = max(SpTabMaxC[i][j-1], SpTabMaxC[i + step][j-1]);
            SpTabMaxD[i][j] = max(SpTabMaxD[i][j-1], SpTabMaxD[i + step][j-1]);
        }
    }
}

ll UnFairD() {
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        if (c[i]+k >= d[i])
            continue;
        int Low = i;
        int Hi = i;
        //Tim Low nho nhat ma Di >= D[L...i] va Fight van con unfair
        //Tim Hi lon nhat ma Di > D[i+1...R] va Fight van con unfair
        //Co the dung stack và Deque de tim Low va Hi
        for (int j = 16; j>=0; j--) {
            if (((Hi + (1 << j)) <= n) && (SpTabMaxD[Hi+1][j] <= d[i]) && (SpTabMaxC[Hi+1][j] + k < d[i]))
                Hi += (1 << j);
        }
        for (int j = 16; j>=0; j--) {
            if (((Low - (1 << j)) >= 1) && (SpTabMaxD[Low - (1 << j)][j] < d[i]) && (SpTabMaxC[Low - (1 << j)][j] + k < d[i]))
                Low -= (1 << j);
        }
        ll tmp = 1LL*(i - Low + 1)*(Hi - i + 1);
        ans += tmp;
    }
    return ans;
}

ll UnFairC() {
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        if (d[i]+k >= c[i])
            continue;
        int Low = i;
        int Hi = i;
        //Tim Low nho nhat ma Ci >= C[L...i] va Fight van con unfair
        //Tim Hi lon nhat ma Ci > C[i+1...R] va Fight van con unfair
        //Co the dung stack và Deque de tim Low va Hi
        for (int j = 16; j>=0; j--) {
            if (((Hi + (1 << j)) <= n) && (SpTabMaxC[Hi+1][j] <= c[i]) && (SpTabMaxD[Hi+1][j] + k < c[i]))
                Hi += (1 << j);
        }
        for (int j = 16; j>=0; j--) {
            if (((Low - (1 << j)) >= 1) && (SpTabMaxC[Low - (1 << j)][j] < c[i]) && (SpTabMaxD[Low - (1 << j)][j] + k < c[i]))
                Low -= (1 << j);
        }
        ll tmp = 1LL*(i - Low + 1)*(Hi - i + 1);
        ans += tmp;
    }
    return ans;
}

ll Solution() {
    ll ans = 1LL*n*(n+1LL)/2;
    ans = ans - UnFairC() - UnFairD();
    return ans;
}

void Solve() {
    MakeLog2();
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        ReadData();
        MakeSparseTables();
        cout << "Case #" << i << ": " << Solution() << '\n';
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
