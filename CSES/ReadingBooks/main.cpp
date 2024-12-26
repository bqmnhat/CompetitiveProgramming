#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n;
ll t[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> t[i];
}

ll Solution() {
    sort(t+1, t+1+n, greater<ll>());
    ll SumSmaller = 0;
    for (int i=2; i<=n; i++)
        SumSmaller += t[i];
    if (t[1] >= SumSmaller)
        return (2*t[1]);
    return (t[1]+SumSmaller);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
