#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n;
ll x[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i];
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    return 0;
}
