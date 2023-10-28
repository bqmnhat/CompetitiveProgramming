#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
struct Matrix {
    vector<vector<ll>> a;
    int n, m;

    Matrix(int n = 0, int m = 0): n(n), m(m) {
        a.assign(n, vector<ll>(m, 0));
    }
};
const ll Mod = 1e9 + 7;

// Tools prep part

Matrix operator* (const Matrix& a, const Matrix& b) {
    Matrix c(a.n, b.m);
    for (int i=0; i<a.n; i++)
        for (int j=0; j<b.m; j++)
            for (int k=0; k<a.m; k++)
                c.a[i][j] = (c.a[i][j] + (a.a[i][k]*b.a[k][j])%Mod)%Mod;
    return c;
}

Matrix Identity(int n) {
    Matrix c(n, n);
    for (int i=0; i<n; i++)
        c.a[i][i] = 1;
    return c;
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

// Solution part

// Solution for first observation: brute force and 1 WA
ll Solution() {
    Matrix base(3, 1), mt(3, 3), tmp; // Dp euation: dp[i] = dp[i-1] + dp[i-3]
    //Corner case: n == 1;
    if (n == 1)
        return 2;
    base.a[0][0] = 1;
    base.a[1][0] = 2;
    base.a[2][0] = 3;
    mt.a[0][1] = mt.a[1][2] = mt.a[2][0] = mt.a[2][2] = 1;
    tmp = FastPow(mt, n-2); // n-2 because we start at dp[2]
    tmp = tmp * base;
    return tmp.a[2][0];
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
