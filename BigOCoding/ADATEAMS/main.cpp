#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a, b, d, MOD = 1e9 + 7;

int Factorial(int x) {
    int ans = 1;
    for (int i=1; i<=x; i++)
        ans = ((ans%MOD)*(i%MOD))%MOD;
    return ans;
}

int SolutionForTestCase() {
    long long ans, factn, facta, factNsubA, factb, factd, factBsubD;
    factn = Factorial(n);
    facta = Factorial(a);
    factNsubA = Factorial(n - a);
    factb = Factorial(b);
    factd = Factorial(d);
    factBsubD = Factorial(b - d);
    ans = (((factn/facta*factNsubA)%MOD) * (factb/(factd*factBsubD))%MOD)%MOD;
    return ans;
}

void Solve() {
    while (cin >> n >> a >> b >> d)
        cout << SolutionForTestCase() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
