#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k;
long long a[1000001], mincd[1000001], cd[1000001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        cd[i] = cd[i-1] + a[i];
        if (cd[i] < mincd[i-1])
            mincd[i] = cd[i];
        else
            mincd[i] = mincd[i-1];
    }
}

long long MaxSeq() {
    long long ans = -1e9;
    int strt, End;
    for (int i=k; i<=n; i++) {
        long long tmp = cd[i] - mincd[i-k];
        if (tmp > ans) {
            ans = tmp;
            strt = i-k+1;
            End = i;
        }
    }
    cout << strt << " " << End << endl;
    return ans;
}

int main()
{
    freopen("SUBSEQ.INP", "r", stdin);
    freopen("SUBSEQ.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    cout << MaxSeq();
    return 0;
}
