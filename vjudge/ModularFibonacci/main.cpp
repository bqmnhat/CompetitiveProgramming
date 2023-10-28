#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<long long>> MulTab;
int n, m;

MulTab MatMul(MulTab a, MulTab b, long long mod) {
    MulTab ans(2);
    ans[0].resize(2);
    ans[1].resize(2);
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            for (int k=0; k<2; k++)
                ans[i][j] = ((ans[i][j]%mod) + ((a[i][k]%mod)*(b[k][j]%mod))%mod)%mod;
    return ans;
}

MulTab ExpMat(MulTab a, int x, long long mod) {
    MulTab b(2);
    b[0].resize(2);
    b[1].resize(2);
    if (x == 0) {
        b[0][0] = b[1][1] = 1;
        return b;
    }
    if (x == 1)
        return a;
    b = ExpMat(a, x/2, m);
    b = MatMul(b,b,m);
    if (x&1)
        b = MatMul(b,a,m);
    return b;
}

int Solution() {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    m = (1 << m);
    MulTab a(2);
    a[0].resize(2);
    a[1].resize(2);
    a[0][0] = a[0][1] = a[1][0] = 1;
    a = ExpMat(a, n-1, m);
    return a[0][0];
}

void Solve() {
    while (cin >> n >> m)
        cout << Solution() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
