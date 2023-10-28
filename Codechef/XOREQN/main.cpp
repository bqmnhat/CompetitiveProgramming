#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n, t, cnt[61];
long long a[1000001], Max = 0, tmp[1000001];

void Init() {
    Max = 0;
    for (long long i=0; i<60; i++)
        cnt[i] = 0;
}

void ReadData() {
    for (long long i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i] > Max)
            Max = a[i];
    }
}

long long MaxNumOfBit(long long M)  {
    long long ans = -1;
    while (M > 0) {
        ans++;
        M = (M>>1);
    }
    return ans;
}

long long Solution() {
    long long ans = 0;
    long long MaxBit = MaxNumOfBit(Max);
    for (long long i=0; i<=MaxBit; i++) {
        for (long long j=1; j<=n; j++) {
            tmp[j] = (a[j]&1);
            if (tmp[j] == 1)
                cnt[i]++;
            a[j] = (a[j]>>1);
        }
        if (cnt[i]%2 == 1) {
            ans = ans + (1LL<<i);
            for (long long j=1; j<=n; j++) {
                if (tmp[j] == 1)
                    a[j] = a[j] + 1LL;
            }
        }
    }
    for (long long j=1; j<=n; j++) {
        tmp[j] = (a[j]&1);
        if (tmp[j] == 1)
            cnt[MaxBit+1]++;
        a[j] = (a[j]>>1LL);
    }
    if (cnt[MaxBit+1]%2 == 1) {
        return -1;
    }
    return ans;
}

void Solve() {
    for (long long i=1; i<=t; i++) {
        Init();
        cin >> n;
        ReadData();
        cout << Solution() << '\n';
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
