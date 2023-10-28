#include <iostream>
#include <bits/stdc++.h>
#define MaxN 52
#define MaxC 256
using namespace std;
typedef long long ll;
struct Matrix {
    int n, m;
    vector<vector<ll>> a;

    Matrix(int n = 0, int m = 0): n(n), m(m) {
        a.assign(n, vector<ll>(m, 0));
    }
};
ll n;
int m, k, chval[MaxC+1];
const ll Mod = 1e9 + 7;

void CalChVal() {
    int cnt = 0;
    for (int i='a'; i<='z'; i++) {
        chval[i] = cnt;
        cnt++;
    }
    for (int i='A'; i<='Z'; i++) {
        chval[i] = cnt;
        cnt++;
    }
}

Matrix GetUnit(int n) {
    Matrix unit(n, n);
    for (int i=0; i<n; i++)
        unit.a[i][i] = 1;
    return unit;
}

Matrix operator* (Matrix a, Matrix b) {
    Matrix ans(a.n, b.m);
    for (int i=0; i<a.n; i++)
        for (int j=0; j<b.m; j++)
            for (int k=0; k<a.m; k++)
                ans.a[i][j] = (ans.a[i][j] + (a.a[i][k]*b.a[k][j])%Mod)%Mod;
    return ans;
}

Matrix operator^(Matrix base, ll e) {
    Matrix ans = GetUnit(base.n);
    while (e > 0LL) {
        if (e&1)
            ans = ans * base;
        base = base*base;
        e >>= 1LL;
    }
    return ans;
}

ll Solution() {
    Matrix f(m, m);
    f.a.assign(m, vector<ll>(m, 1));
    string s;
    for (int i=1; i<=k; i++) {
        cin >> s;
        f.a[chval[s[0]]][chval[s[1]]] = 0;
    }
    Matrix base(m, 1);
    base.a.assign(m, vector<ll>(1, 1));
    Matrix tmp = (f^(n-1LL))*base;
    ll ans = 0;
    for (int i=0; i<m; i++)
        ans = (ans + tmp.a[i][0])%Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    CalChVal();
    cout << Solution();
    return 0;
}
