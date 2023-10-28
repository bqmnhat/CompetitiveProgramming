#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef __int128_t i128;
typedef long long ll;
const i128 Mod = 1e15 + 7;
struct Matrix {
    vector<vector<i128>> a;
    int n, m;

    Matrix(int n = 0, int m = 0): n(n), m(m) {
        a.assign(n, vector<i128>(m, 0));
    }
};
int t;
ll n;

Matrix operator * (const Matrix& a, const Matrix& b) {
    Matrix c(a.n, b.m);
    for (int i=0; i<a.n; i++)
        for (int j=0; j<b.m; j++)
            for (int k=0; k<a.m; k++)
                c.a[i][j] = (c.a[i][j] + (a.a[i][k] * b.a[k][j])%Mod)%Mod;
    return c;
 }

 Matrix Identity(int n) {
    Matrix id(n, n);
    for (int i=0; i<n; i++)
        id.a[i][i] = 1;
    return id;
 }

 Matrix FastPow(Matrix base, ll e) {
    Matrix ans = Identity(base.n);
    while (e > 0) {
        if (e&1LL)
            ans = ans*base;
        base = base*base;
        e >>= 1LL;
    }
    return ans;
 }

 ll Solution() {
    if (n == 1)
        return 1;
    if (n == 2)
        return 3;
    if (n == 3)
        return 6;
    Matrix original(4, 1), mul(4, 4), tmp, res;
    original.a[0][0] = 6;
    original.a[1][0] = 3;
    original.a[2][0] = 2;
    original.a[3][0] = 1;
    mul.a[0][0] = mul.a[0][1] = mul.a[0][2] = mul.a[0][3] =
    mul.a[1][1] = mul.a[1][2] = mul.a[1][3] =
    mul.a[2][1] = mul.a[3][2] = 1;
    tmp = FastPow(mul, n - 3);
    res = tmp*original;
    return res.a[0][0];
 }

 void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << Solution() <<'\n';
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
