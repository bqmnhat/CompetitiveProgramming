#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[16], SumRev = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        SumRev = (SumRev%360 + (360 - a[i])%360)%360;
    }
}

bool IsSol(int k) {
    int p = 0, i = 1;
    while (i <= n) {
        int tmp = k%2;
        if (tmp == 0)
            p = (p%360 + (360 - a[i])%360)%360;
        else
            p = (p%360 + a[i]%360)%360;
        k = (k >> 1);
        i++;
    }
    return (p == 0);
}

bool CanSolve() {
    for (int i=0; i<(1 << n); i++)
        if (IsSol(i))
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    if (CanSolve())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
