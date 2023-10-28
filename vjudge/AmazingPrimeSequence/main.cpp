#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000000
using namespace std;
typedef long long ll;
int t, n, d[MaxN+5];
ll a[MaxN+5];

void MakeD() {
    for (int i=2; i*i<=MaxN; i++) {
        if (d[i] == 0) {
            for (int j=i; i*j<=MaxN; j++) {
                if (d[i*j] == 0)
                    d[i*j] = i;
                else
                    d[i*j] = min(d[i*j], i);
            }
        }
    }
}

void MakeA() {
    a[0] = a[1] = 0;
    for (int i=2; i<=MaxN; i++) {
        ll fi = d[i];
        if (fi == 0)
            fi = i;
        a[i] = a[i-1] + 1LL*fi;
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << a[n] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeD();
    MakeA();
    cin >> t;
    Solve();
    return 0;
}
