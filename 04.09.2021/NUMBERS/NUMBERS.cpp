#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, ltk[100];
long long sum[100];

int SumOfDigits(long long x) {
    int ans = 0;
    while (x > 0) {
        ans = ans + (x%10);
        x = x/10;
    }
    return ans;
}

long long Solution() {
    long long ans = 1e18, TargetSum;
    for (int i=1; i<=1000000; i++) {
        TargetSum = SumOfDigits(i);
        if (ltk[TargetSum] < n) {
            ltk[TargetSum]++;
            sum[TargetSum] += i;
        }
        if ((sum[TargetSum] < ans) && (ltk[TargetSum] == n))
            ans = sum[TargetSum];
    }
    return ans;
}

int main()
{
    freopen("NUMBERS.INP", "r", stdin);
    freopen("NUMBERS.OUT", "w", stdout);
    cin >> n;
    cout << Solution();
    return 0;
}
