#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, k, a[MaxN+1], spTab[MaxN+1][20], log_2[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        spTab[i][0] = a[i];
    }
}

void MakeLog2() {
    log_2[0] = log_2[1] = 0;
    for (int i=2; i<=n; i++)
        log_2[i] = log_2[i/2] + 1;
}

void MakeSpTab() {
    int step;
    for (int j = 1; (1 << j) <= n; j++) {
        step = (1 << (j-1));
        for (int i=1; i + 2*step<=n+1; i++)
            spTab[i][j] = min(spTab[i][j-1], spTab[i+step][j-1]);
    }
}

int GetMin(int l, int r) {
    int k = log_2[r - l + 1];
    return min(spTab[l][k], spTab[r - (1 << k) + 1][k]);
}

void SolvePrimes() {
    for (int i=1; i<=n-k+1; i++)
        cout << GetMin(i, i + k - 1) << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    MakeLog2();
    MakeSpTab();
    SolvePrimes();
    return 0;
}
