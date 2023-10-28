#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[100001], b[100001], lb = 0, freq[100001], CdFreq[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
}

void CompressB() {
    sort(b+1, b+1+n);
    for (int i=1; i<=n; i++) {
        if (b[i] != b[i-1]) {
            lb++;
            b[lb] = b[i];
        }
        freq[lb]++;
    }
}

void MakeCdFreq() {
    for (int i=1; i<=lb; i++)
        CdFreq[i] = CdFreq[i-1] + freq[i];
}

int BinSearch(int val) {
    int lo = 1, hi = lb;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (b[m] == val)
            return m;
        else if (b[m] > val)
            hi = m - 1;
        else
            lo = m + 1;
    }
    return -1;
}

void Solve() {
    for (int i=1; i<=n; i++) {
        int tmp = BinSearch(a[i]), smaller, larger;
        smaller = CdFreq[tmp-1];
        larger = n - CdFreq[tmp];
        cout << smaller << " " << larger << '\n';
    }
}

int main()
{
    freopen("STAT.INP", "r", stdin);
    freopen("STAT.OUT", "w", stdout);
    cin >> n;
    ReadData();
    CompressB();
    MakeCdFreq();
    Solve();
    return 0;
}
