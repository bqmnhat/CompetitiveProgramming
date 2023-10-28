#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

double SumFrac() {
    double ans = 0;
    for (int i=1; i<=n; i++)
        ans = ans + (1.0/double(i));
    return ans;
}

int main()
{
    cin >> n;
    cout << fixed << setprecision(6) << SumFrac();
    return 0;
}
