#include <iostream>
#include <bits/stdc++.h>
#define MaxN 700
using namespace std;
typedef unsigned long long ll;
//typedef vector<int> BigNum;
int n;
vector<int> g[MaxN+1];
// Sum of 2 Big Numbers
/*BigNum operator + (BigNum a, BigNum b) {
    BigNum ans;
    int i = 0, j = 0, r = 0;
    while ((i < a.size()) || (j < b.size())) {
        if (i < a.size())
            r += a[i++];
        if (j < b.size())
            r += b[j++];
        ans.push_back(r%10);
        r = r/10;
    }
    if (r > 0)
        ans.push_back(r);
    return ans;

}

BigNum operator * (BigNum a, int b) // Multiplication of 1 Big Number and 1 integer
{
    BigNum ans;
    int r = 0;
    for (int i = 0; i < a.size(); ++i) {
        r = r + a[i]*b;
        ans.push_back(r%10);
        r = r/10;
    }
    if (r > 0)
        ans.push_back(r);
    return ans;
}

BigNum pow10(BigNum a, int n) { //ham mu 10
    BigNum ans(a.size()+n, 0);
    for (int i = 0, j = n; i < a.size(); ++i, ++j)
        ans[j] = a[i];
    return ans;
}

BigNum operator * (BigNum a, BigNum b) // Multiplication of 2 BigNums
{
    BigNum ans;
    for (int i = 0; i < b.size(); ++i) {
        BigNum tmp = a*b[i]; // Use Multiplication operator of 1 BigNum and 1 integer
        tmp = pow10(tmp, i);
        ans = ans + tmp;
    }
    return ans;
}*/

void ReadGraph() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFS(int u, int p, vector<ll>& dp, vector<ll>& prod, vector<ll>& DeeperProd) {
    dp[u] = prod[u] = DeeperProd[u] = 1;
    for (int v: g[u]) {
        if (v == p)
            continue;
        DFS(v, u, dp, prod, DeeperProd);
        prod[u] *= dp[v];
        DeeperProd[u] *= prod[v];
    }
    cout << "Prod " << u << ' ' << prod[u] << '\n';
    cout << "DeeperProd " << u << ' ' << DeeperProd[u] << '\n';
    int gsize;
    if (p == -1)
        gsize = g[u].size();
    else
        gsize = g[u].size()-1LL;
    dp[u] = max(prod[u], ll(gsize + 1LL)*DeeperProd[u]);
    for (int v: g[u])
        if (v != p)
            dp[u] = max(dp[u], max((prod[u]/dp[v])*(gsize + 1LL)*DeeperProd[v], dp[v]*(prod[u]/dp[v])*(gsize - 1LL)*);
    cout << "dp " << u << ' ' << dp[u] << '\n';
    cout << '\n';
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        cout << "\nrooted " << i << '\n';
        vector<ll> dp(n+1, 1), prod(n+1, 1), DeeperProd(n+1, 1);
        DFS(i, -1, dp, prod, DeeperProd);
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadGraph();
    cout << Solution();
    return 0;
}
