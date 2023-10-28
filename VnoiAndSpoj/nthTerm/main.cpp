#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n, a, b, c;
const ll Mod = 10007;
struct Matrix {
    vector<vector<ll>> a;
    int n, m;

    Matrix(int n = 0, int m = 0): n(n), m(m) {
        a.assign(n, vector<ll>(m, 0));
    }
};

Matrix operator* (const Matrix& a, const Matrix& b) {
    Matrix c(a.n, b.m);
    for (int i=0; i<a.n; i++)
        for (int j=0; j<b.m; j++)
            for (int k=0; k<a.m; k++)
                c.a[i][j] = ((a.a[i][k]*b.a[k][j])%Mod + c.a[i][j])%Mod;
    return c;
}

Matrix Identity(int n) {
    Matrix ans(n, n);
    for (int i=0; i<n; i++)
        ans.a[i][i] = 1;
    return ans;
}

Matrix FastPow(Matrix& base, ll e)  {
    Matrix ans = Identity(base.n);
    while (e > 0) {
        if (e&1)
            ans = ans * base;
        base = base * base;
        e >>= 1LL;
    }
    return ans;
}

void SolveTestCase() {
    Matrix mat(4, 4), unit(4, 1), tmp;
    mat.a[0][3] = mat.a[1][0] = mat.a[2][1] = mat.a[3][3] = 1;
    mat.a[0][0] = a;
    mat.a[0][2] = b;
    unit.a[0][0] = 0;
    unit.a[1][0] = 0;
    unit.a[2][0] = 0;
    unit.a[3][0] = c;
    tmp = FastPow(mat, n-2);
    tmp = tmp*unit;
    cout << tmp.a[0][0] << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> a >> b >> c;
        cout << "Case " << i << ": ";
        SolveTestCase();
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
