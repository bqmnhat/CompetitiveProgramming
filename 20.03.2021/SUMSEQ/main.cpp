#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100001], cd[200001],s;

void ReadData() {
    int k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        cd[i] = cd[i-1] + a[i];
    }
    k = n+1;
    for (int i=1; i<=n; i++) {
        cd[k] = cd[k-1] + a[i];
        k++;
    }
}

int BinSearch(int lo, int hi, int st) {
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if (cd[mid] - cd[st-1] == s) {
            ans = mid;
            hi = mid-1;
        }
        else if (cd[mid] - cd[st-1] < s) {
            lo = mid+1;
        }
        else if (cd[mid] - cd[st-1] > s) {
            hi = mid-1;
        }
    }
    return ans;
}

void Solve() {
    int bd = 0, len = 2*n;
    for (int i=1; i<=n; i++) {
        int j = BinSearch(i,2*n,i);
        if ((j != 0) && (j-i+1 < len)) {
            len = j-i+1;
            if (i>n)
                bd = i-n;
            else
                bd = i;
        }
    }
    if (bd > 0)
        cout << bd << " " << len;
    else
        cout << "0";
}

int main()
{
    freopen("SUMSEQ.INP", "r", stdin);
    freopen("SUMSEQ.OUT", "w", stdout);
    cin >> n >> s;
    ReadData();
    Solve();
    return 0;
}
