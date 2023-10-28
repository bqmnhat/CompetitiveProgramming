#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
typedef long long ll;
int n, t, q, cnt[MaxN+1], c[MaxN+1][MaxN+1];
string s;
const ll Mod = 1e9 + 7;

vector<int> MakeZFunction(string s) {
    int n = s.length(), l = 0, r = 0;
    vector<int> z(n);
    z[0] = n;
    for (int i=1; i<n; i++) {
        if (i <= r)
            z[i] = min(z[i-l], r-i+1);
        while ((i + z[i] < n) && (s[i + z[i]] == s[z[i]]))
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

void CountEqualStrings(string s) {
    int n = s.length();
    for (int i=0; i < n; i++) {
        string tmp = "";
        for (int j=i; j<n; j++)
            tmp.push_back(s[j]);
        vector<int> z = MakeZFunction(tmp);
        sort(z.begin(), z.end(), greater<int>());
        for (int i=0; i<z.size()-1; i++) {
            if (z[i] != z[i+1])
                cnt[i+1] += (z[i] - z[i+1]);
        }
        if  ((z[int(z.size()) - 1] != 0) && (z[int(z.size()) - 1] != z[int(z.size()) - 2]))
            cnt[z.size()]++;
    }
    int sum = 0;
    for (int i=n; i>=1; i--) {
        cnt[i] -= sum;
        sum += cnt[i];
    }
}

void MakeCHOOSE() {
    for (int i=1; i<=MaxN; i++)
        c[i][0] = 1;
    for (int i=1; i<=MaxN; i++) {
        for (int j=1; j<=i; j++) {
            if (i == j) {
                c[i][j] = 1;
                continue;
            }
            c[i][j] = (1LL*c[i-1][j] + 1LL*c[i-1][j-1])%Mod;
        }
    }
}

int Query(int k) {
    int ans = 0;
    if (k > n)
        return 0;
    for (int i=k; i<=n; i++)
        ans = (1LL*ans + (1LL*cnt[i]*c[i][k])%Mod)%Mod;
    return ans;
}

void Solve() {
    MakeCHOOSE();
    for (int i=1; i<=t; i++) {
        cin >> n >> q >> s;
        for (int i=0; i<=n; i++)
            cnt[i] = 0;
        CountEqualStrings(s);
        for (int i=1; i<=q; i++) {
            int k;
            cin >> k;
            cout << Query(k) << '\n';
        }
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
