#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a, MaxAns = 1000000000;
long long b, c;

long long SumDig(long long X) {
    long long ans = 0;
    while (X > 0) {
        ans += (X%10);
        X = X/10;
    }
    return ans;
}

long long Power(int base, int e) {
    long long ans = 1;
    for (int i=1; i<=e; i++) {
        ans = ans * base;
    }
    return ans;
}

void Solve() {
    bool Exist = false;
    for (int i=1; i<=81; i++) {
        long long PowA = Power(i,a);
        long long tmp = PowA*b + c;
        if ((SumDig(tmp) == i) && (tmp <= MaxAns)) {
            cout << tmp << '\n';
            Exist = true;
        }
    }
    if (Exist == false)
        cout << "No solution";
}

int main()
{
    freopen("EQUATION.INP", "r", stdin);
    freopen("EQUATION.OUT", "w", stdout);
    cin >> a >> b >> c;
    Solve();
    return 0;
}
