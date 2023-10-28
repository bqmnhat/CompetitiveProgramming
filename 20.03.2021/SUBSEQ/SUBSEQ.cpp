#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k;
long long a[1000001], cd[1000001], maxcd[1000001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        cd[i] = cd[i-1] + a[i];
    }
}

void MakeMaxCD() {
    long long MaxVal = cd[n];
    maxcd[n] = MaxVal;
    for (int i=n-1; i>=1; i--) {
        if (cd[i] > MaxVal)
            MaxVal = cd[i];
        maxcd[i] = MaxVal;
    }
}

long long MaxSeq() {
    long long ans = -1e9;
    for (int i=1; i<=n-k+1; i++) {
        long long tmp = maxcd[i+k-1]-cd[i-1];
        if (tmp > ans)
            ans = tmp;
    }
    return ans;
}

int main()
{
    freopen("SUBSEQ.INP", "r", stdin);
    freopen("SUBSEQ.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    MakeMaxCD();
    cout << MaxSeq();
    return 0;
}
