#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int k;

int CountKOfNInBaseD(ll n, ll d) {
    int ans = 0;
    vector<ll> dig;
    dig.clear();
    if (n == 0)
        dig.push_back(0);
    while (n > 0) {
        int tmp = n%d;
        n = n/d;
        dig.push_back(tmp);
    }
    int i = 0;
    while ((i < dig.size()) && (dig[i] == k)) {
        ans++;
        i++;
    }
    return ans;
}

void Solve() {
    int ans = 0, ansId = 2;
    for (int i=2; i<=10; i++) {
        int cnt = CountKOfNInBaseD(n, i);
        if (cnt > ans) {
            ans = cnt;
            ansId = i;
        }
    }
    cout << ansId << ' ' << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    Solve();
    return 0;
}
