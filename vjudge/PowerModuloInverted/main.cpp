#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
using namespace std;
typedef long long ll;
int x, z, k;
unordered_map<int, int> f;

int BSGS(int a, int b, int m) {
    int g, alpha = 1, add = 0;
    a %= m;
    b %= m;
    g = __gcd(a, m);
    while (g > 1) {
        if (b == alpha)
            return add;
        if (b % g != 0)
            return -1;
        b /= g;
        m /= g;
        add++;
        alpha = (1LL*alpha*(a/g)) % m;
        g = __gcd(a, m);
    }
    int n = sqrt(m) + 1, an = 1;
    for (int i = 1; i<=n; i++)
        an = (1LL*an*a)%m;
    int tmp = b;
    for (int i=0; i<=n; i++) {
        f[tmp] = i;
        tmp = (1LL * tmp * a)%m;
    }
    int cur = alpha;
    for (int i=1; i<=n; i++) {
        cur = (1LL * cur * an)%m;
        if (f.count(cur)) {
            int ans = i*n - f[cur] + add;
            return ans;
        }
    }
    return -1;
}

void Solve() {
    while ((cin >> x >> z >> k) && ((x != 0) && (z != 0) && (k != 0))) {
        f.clear();
        int ans = BSGS(x, k, z);
        if (ans == -1)
            cout << "No Solution\n";
        else
            cout << ans << '\n';
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
