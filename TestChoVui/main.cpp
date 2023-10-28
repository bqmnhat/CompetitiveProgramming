#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, preSum[101];

void MakePreSum() {
    for (int i=1; i<=n; i++)
        preSum[i] = preSum[i-1] + i;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    MakePreSum();
    return 0;
}
