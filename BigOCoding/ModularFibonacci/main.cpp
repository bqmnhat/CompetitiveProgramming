#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, Mod;
struct Matrix {
    vector<vector<ll>> a;
    int n, m;

    Matrix(int n = 0, int m = 0): n(n), m(m) {
        a.assign(n, vector<ll>(m, 0));
    }
};

Matrix operator* (const Matrix& a, const Matrix& b) {
    Matrix c(a.n, b.m);
    for (int i = 0; i<a.n; i++)
        for (int j=0; j<b.m; j++)
            for (int k = 0; k<a.m; k++)
                c.a[i][j] = ((a.a[i][k]*b.a[k][j])%Mod + c.a[i][j])%Mod;
    return c;
}

Matrix Identity(int n) {
    Matrix mat(n, n);
    for (int i=0; i<n; i++)
        mat.a[i][i] = 1;
    return mat;
}

Matrix FastPow(Matrix& base, ll e) {
    Matrix ans = Identity(base.n);
    while (e > 0) {
        if (e&1)
            ans = ans*base;
        base = base * base;
        e >>= 1LL;
    }
    return ans;
}

void SolveTestCase() {
    Matrix mat(2, 2), unit(2, 1), tmp, ans;
    unit.a[0][0] = 0;
    unit.a[1][0] = 1;
    mat.a[0][0] = 0;
    mat.a[0][1] = mat.a[1][0] = mat.a[1][1] = 1;
    tmp = FastPow(mat, n);
    ans = tmp*unit;
    cout << ans.a[0][0]%Mod << '\n';
}

void Solve() {
    while (cin >> n >> m) {
        Mod = (1LL << m);
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
