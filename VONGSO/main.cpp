#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll b[10001], a[10001], sum = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        sum += b[i];
    }
}

void CalA1A2() {
    ll SumOfA = sum/3;
    if (n%3 == 0) {
        a[1] = 1;
        a[2] = 3;
    }
    else if (n % 3 == 1) {
        ll val1,val2;
        val1 = val2 = SumOfA;
        int i=3;
        while (i <= n) {
            val1 = val1 - b[i];
            i += 3;
        }
        i = 4;
        while (i <= n) {
            val2 = val2 - b[i];
            i += 3;
        }
        a[1] = val1;
        a[2] = val2;
    }
    else {
        ll val1,val2;
        val1 = val2 = SumOfA;
        int i=5;
        while (i <= n) {
            val1 = val1 - b[i];
            i += 3;
        }
        i = 6;
        while (i <= n) {
            val2 = val2 - b[i];
            i += 3;
        }
        a[1] = b[2] - val1;
        a[2] = b[3] - val2 + b[1];
    }
}

void Solve() {
    CalA1A2();
    for (int i=3; i<=n; i++)
        a[i] = b[i-1] - a[i-1] - a[i-2];
    for (int i=1; i<=n; i++)
        cout << a[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
