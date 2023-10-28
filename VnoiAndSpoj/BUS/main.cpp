#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
#define MaxM 20000
using namespace std;
typedef long long ll;
int n, m;
ll Time[MaxN+5];
vector<ll> a;

void ReadData() {
    for (int i=1; i<=n; i++) {
        ll ti;
        int k;
        cin >> ti >> k;
        Time[i+1] = Time[i] + ti;
        for (int j=1; j<=k; j++) {
            ll ai;
            cin >> ai;
            a.push_back(max(0LL, ai - Time[i]));
        }
    }
}

ll Solution() {
    sort(a.begin(), a.end());
    ll res = Time[n+1] + a[min((int)a.size() - 1, m-1)];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
