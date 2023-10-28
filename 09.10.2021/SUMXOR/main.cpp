#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

long long SumXor() {
    long long sum = 0;
    for (long long x=0; x<=31; x++) {
        long long cnt1 = 0, cnt0 = 0;
        for (int i=1; i<=n; i++) {
            if ((a[i] & 1) == 1)
                cnt1++;
            else
                cnt0++;
            a[i] = (a[i]>>1);
        }
        sum = sum + (cnt1*cnt0*(1<<x));
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SUMXOR.INP", "r", stdin);
    freopen("SUMXOR.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << SumXor();
    return 0;
}
