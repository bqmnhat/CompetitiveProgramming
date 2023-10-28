#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = 998244353;
ll n;
class Matrix {
    public:
        vector<vector<ll>> a;
        int n, m;

        Matrix(int n = 0, int m = 0): n(n), m(m) {
            a.assign(n, vector<ll>(m, 0));
        }
};

Matrix operator* (const Matrix& m1, const Matrix& m2) {
    Matrix res(m1.n, m1.m);
    for (int i=0; i<m1.n; i++)
        for (int j=0; j<m1.m; j++)
            for (int k=0; k<m2.m; k++)
                res.a[i][j] = (res.a[i][j] + (m1.a[k][j]*m2.a[i][k])%Mod)%Mod;
    return res;
}

Matrix GetId(int n) {
    Matrix res(n, n);
    for (int i=0; i<n; i++)
        res.a[i][i] = 1;
    return res;
}

Matrix FastPow(Matrix x, ll e) {
    Matrix res = GetId(x.n);
    while (e > 0) {
        if (e&1LL)
            res = res*x;
        x = x*x;
        e >>= 1LL;
    }
    return res;
}

ll Solution() {
    Matrix base(6, 1), unit(6, 6);
    unit.a[0][0] = unit.a[1][0] = unit.a[2][1] = unit.a[3][3] = unit.a[4][3] = unit.a[5][4] = 1;
    unit.a[0][2] = unit.a[3][5] = 2;
    unit.a[0][1] = unit.a[3][4] = 4;
    unit.a[0][4] = unit.a[0][5] = 12;
    base.a[0][0] = 12;
    base.a[3][0] = 5;
    base.a[4][0] = 1;
    base.a[5][0] = 1;
    Matrix tmp = FastPow(unit, n-2);
    Matrix ans = base*tmp;
    return ans.a[0][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << Solution();
    return 0;
}
