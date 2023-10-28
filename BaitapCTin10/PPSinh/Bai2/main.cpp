#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long k, n;
int a[101];

long long PowN(int k) {
    long long ans = 1;
    for (int i=1; i<=k; i++)
        ans = ans*n;
    return ans;
}

void PrintAns(int l) {
    for (int i=0; i<k; i++)
        cout << a[i] << ' ';
    cout << '\n';
}

void NextN(long long xn) {
    int la = 0;
    while (xn > 0) {
        long long tmp = (xn%n);
        xn = xn/n;
        la++;
        a[k - la] = tmp;
    }
    PrintAns(la);
}

void Solve() {
    long long m = PowN(k);
    for (long long i=0; i<m; i++)
        NextN(i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai2.INP", "r", stdin);
    freopen("Bai2.OUT", "w", stdout);
    cin >> n >> k;
    if ((k > 0) && (n > 0))
        Solve();
    return 0;
}
