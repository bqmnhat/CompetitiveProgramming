#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[300001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Solve() {
    sort(a+1, a+1+n);
    for (int i=1; i<=n; i++)
        cout << a[i] << " ";
}

int main()
{
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
