#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int d[1000001], NumOfDiv[1000001], cd[1000001];
int a,b,t;
map <int, ll> mu;

void MakeD() {
    for (int i=2; i*i<=1000000; i++)
        if (d[i] == 0)
            for (int j=i; i*j <= 1000000; j++)
                d[i*j] = i;
}

ll CntDiv(int x) {
    mu.clear();
    while (x > 1) {
        int p = d[x];
        if (p == 0)
            p = x;
        mu[p]++;
        x = x/p;
    }
    ll ans = 1;
    for (auto i = mu.begin(); i!= mu.end(); i++)
        ans = ans*((*i).second + 1);
    return ans;
}

void MakeNumOfDiv() {
    for (int i=1; i<=1000; i++) {
        int tmp = i*i;
        NumOfDiv[tmp] = CntDiv(tmp);
    }
}

void MakeCD() {
    for (int i=1; i<=1000000; i++) {
        cd[i] = cd[i-1];
        if ((NumOfDiv[i] == 9) && (i % 3 == 0))
            cd[i]++;
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> a >> b;
        int ans = cd[b] - cd[a-1];
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SDB.INP", "r", stdin);
    freopen("SDB.OUT", "w", stdout);
    MakeD();
    MakeNumOfDiv();
    MakeCD();
    cin >> t;
    Solve();
    return 0;
}
