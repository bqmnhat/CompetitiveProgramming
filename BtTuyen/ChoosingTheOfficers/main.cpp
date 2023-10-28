#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n, a[1001], sum = 0, Modulo = 1000000007;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

long long Solution() {
    long long ans = sum-n;
    for (int i=1; i<=n; i++)
        ans = ((ans%Modulo)*(a[i]%Modulo))%Modulo;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
