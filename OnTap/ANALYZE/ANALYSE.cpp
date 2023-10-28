#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int x[51], n;

void PrintAns(int k) {
    for (int i=1; i<=k; i++)
        cout << x[i] << " ";
    cout << '\n';
}

void Try(int i, int sum) {
    for (int j=x[i-1]; j<=n-sum; j++) {
        if(sum + j == n) {
            x[i] = j;
            PrintAns(i);
        }
        else if (sum + j < n) {
            x[i] = j;
            Try(i+1, sum + j);
        }
    }
}

void Solve() {
    for (int i=1; i<n; i++) {
        x[1] = i;
        Try(2, i);
    }
    cout << n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ANALYSE.INP", "r", stdin);
    freopen("ANALYSE.OUT", "w", stdout);
    cin >> n;
    Solve();
    return 0;
}
