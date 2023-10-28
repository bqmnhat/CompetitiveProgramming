#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,x,a[100001],val[100001], freq[100001],l;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void Compress() {
    sort(a+1, a+1+n);
    int d = 1,k = 1;
    val[1] = a[1];
    freq[1] = 1;
    for (int i = 2; i<=n; i++) {
        if (a[i] != a[i-1]) {
            ++k;
            val[k] = a[i];
        }
        freq[k] = freq[k] + 1;
    }
    l = k;
}

int BinSearch(int x, int lo, int hi) {
    int m;
    while (lo <= hi) {
        m = (lo + hi)/2;
        if (a[m] == x)
            return m;
        else if (a[m] < x) {
            lo = m + 1;
        }
        else
            hi = m-1;
    }
    return -1;
}

int PairsX() {
    int ans = 0,j;
    for (int i = 1; i<=l; i++) {
        if (x = 2*a[i]) {
            ans = ans + (freq[i]*(freq[i] - 1)/2);
        }
        else {
            j = BinSearch(x - a[i],i+1,l);
            ans = ans + freq[i]*freq[j];
        }
    }
    return ans;
}

int main()
{
    freopen("SUMX.INP", "r", stdin);
    freopen("SUMX.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cin >> x;
    Compress();
    cout << PairsX();
    return 0;
}
