#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[10000001], la = 0;
int t;

void NextJumping(long long val) {
    long long x = val;
    if ((x%10+1 >= 0) && (x%10+1<=9) && (x*10 + (x%10+1) <= 1000000000)) {
        long long x1 = x*10 + (x%10+1);
        la++;
        a[la] = x1;
        NextJumping(x1);
    }
    if ((x%10-1 >= 0) && (x%10-1<=9) && (x*10 + (x%10-1) <= 1000000000)) {
        long long x2 = x*10 + (x%10-1);
        la++;
        a[la] = x2;
        NextJumping(x2);
    }
}

void MakeA() {
    la++;
    a[la] = 0;
    for (long long i=1; i<=9; i++) {
        la++;
        a[la] = i;
        NextJumping(i);
    }
    sort(a+1,a+1+la);
}

void Solve() {
    for (int i=1; i<=t; i++) {
        int n;
        cin >> n;
        int j=1;
        while ((a[j] <= n) && (j<=la)) {
            cout << a[j] << " ";
            j++;
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    MakeA();
    freopen("JNUM.INP", "r", stdin);
    freopen("JNUM.OUT", "w", stdout);
    cin >> t;
    Solve();
    return 0;
}
