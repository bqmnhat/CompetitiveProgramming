#include <iostream>
#include <bits/stdc++.h>
#define MaxC 257
using namespace std;
typedef long long ll;
ll n;
int m, k, decode[MaxC+1];
const ll Mod = 1e9 + 7;
class Matrix {
    public:
        vector<vector<ll>> a;
        int n, m;

        Matrix(int n = 0, int m = 0): n(n), m(m) {
            a.assign(n, vector<ll>(m, 0));
        }

        Matrix operator* (const Matrix& other) {
            Matrix c(n, other.m);
            for (int i=0; i<n; i++)
                for (int j=0; j<other.m; j++)
                    for (int k=0; k<m; k++)
                        c.a[i][j] = (c.a[i][j] + (a[i][k]*other.a[k][j])%Mod)%Mod;
            return c;
        }
};

Matrix Identity(int n) {
    Matrix c(n, n);
    for (int i=0; i<n; i++)
        c.a[i][i] = 1;
    return c;
}

Matrix operator^ (Matrix base, ll e) {
    Matrix ans = Identity(base.n);
    while (e > 0) {
        if (e&1LL)
            ans = ans * base;
        base = base * base;
        e >>= 1LL;
    }
    return ans;
}

void DecodeDefinition() {
    int cnt = 0;
    for (char i = 'a'; i<='z'; i++) {
        decode[i] = cnt;
        cnt++;
    }
    for (char i = 'A'; i<='Z'; i++) {
        decode[i] = cnt;
        cnt++;
    }
}

ll Solution() {
    Matrix mt(m, m), base(m, 1), tmp;
    for (int i=0; i<m; i++)
        base.a[i][0] = 1;
    string s;
    for (int i=0; i<m; i++)
        for (int j=0; j<m; j++)
            mt.a[i][j] = 1;
    for (int i=1; i<=k; i++) {
        cin >> s;
        mt.a[decode[s[0]]][decode[s[1]]] = 0;
    }
    tmp = mt^(n-1LL);
    tmp = tmp*base;
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
    DecodeDefinition();
    cin >> n >> m >> k;
    cout << Solution();
    return 0;
}
