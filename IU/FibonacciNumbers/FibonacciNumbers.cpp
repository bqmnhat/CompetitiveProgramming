#include <iostream>
#include <bits/stdc++.h>
#define MaxN 45
using namespace std;
typedef long long ll;
int n;
ll fib[MaxN+1];

void MakeFib() {
    fib[1] = fib[2] = 1;
    for (int i=3; i<=n; i++)
        fib[i] = fib[i-1] + fib[i-2];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    MakeFib();
    cout << fib[n];
    return 0;
}
