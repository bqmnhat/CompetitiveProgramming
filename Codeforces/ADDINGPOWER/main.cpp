#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,t;
long long k, tk[65];

void InitTk() {
    for (int i=0; i<=64; i++) {
        tk[i] = 0;
    }
}

void Solve() {
    int j;
    long long ai;
    bool ans = true;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        if (k == 0) {
            if (ai != 0)
                ans = false;
            continue;
        }
        j = -1;
        while (ai > 0) {
            j++;
            if (ai%k > 0)
                tk[j] += ai%k;
            if (tk[j] > 1)
                ans = false;
            ai = ai/k;
        }
    }
    if (!ans)
        cout << "NO";
    else
        cout << "YES";
}

int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        InitTk();
        Solve();
        cout << '\n';
    }
    return 0;
}
