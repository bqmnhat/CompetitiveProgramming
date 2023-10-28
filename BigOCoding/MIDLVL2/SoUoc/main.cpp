#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll cntMu[21];

void Factorize(int x) {
    for (int i=2; i*i<=x && x > 1; i++) {
        while (x%i == 0) {
            x = x/i;
            cntMu[i]++;
        }
    }
    if (x > 1)
        cntMu[x]++;
}

ll Solution() {
    ll ans = 1;
    for (int i=1; i<=n; i++)
        Factorize(i);
    for (int i=1; i<=n; i++)
        ans = ans*(cntMu[i]+1);
    ans--;
    return ans;
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
