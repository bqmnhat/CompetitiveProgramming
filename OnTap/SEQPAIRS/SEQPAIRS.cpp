#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long cda[1001], cdb[1001], suma[1000001], sumb[1000001];
long long freqa[1000001], freqb[1000001];
int m, n, lsa = 0, lsb = 0, lfa = 0, lfb = 0;

void ReadData() {
    long long x,y;
    for (int i=1; i<=m; i++) {
        cin >> x;
        cda[i] = cda[i-1] + x;
    }
    for (int i=1; i<=n; i++) {
        cin >> y;
        cdb[i] = cdb[i-1] + y;
    }
}

void MakeSum() {
    for (int i=1; i<=m; i++) {
        for (int j = 0; j<i; j++) {
            lsa++;
            suma[lsa] = cda[i] - cda[j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j = 0; j<i; j++) {
            lsb++;
            sumb[lsb] = cdb[i] - cdb[j];
        }
    }
}

void MakeFreq(long long freq[], int &lf, long long sum[], int &ls) {
    int i=1, tmp;
    while (i<=ls) {
        tmp = 0;
        while ((sum[i] == sum[i+1]) && (i<ls)) {
            tmp++;
            i++;
        }
        tmp++;
        lf++;
        freq[lf] = tmp;
        sum[lf] = sum[i];
        i++;
    }
    ls = lf;
}

int BinSearch(long long val) {
    int lo = 1, hi = lsb;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (sumb[m] == val)
            return m;
        else if (sumb[m] > val)
            hi = m - 1;
        else
            lo = m + 1;
    }
    return 0;
}

long long Solution() {
    long long ans = 0;
    int i = 2, j = 2;
    sort(suma+1, suma+1+lsa);
    sort(sumb+1, sumb+1+lsb);
    MakeFreq(freqa, lfa, suma, lsa);
    MakeFreq(freqb, lfb, sumb, lsb);
    for (int i=1; i<=lsa; i++) {
        int tmp = BinSearch(suma[i]);
        ans += (freqa[i] * freqb[tmp]);
    }
    return ans;
}

int main()
{
    freopen("SEQPAIRS.INP", "r", stdin);
    freopen("SEQPAIRS.OUT", "w", stdout);
    cin >> m >> n;
    ReadData();
    MakeSum();
    cout << Solution();
    return 0;
}
