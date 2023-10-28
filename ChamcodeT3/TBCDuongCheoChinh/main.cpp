#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

double MainDiagAvg() {
    double ans;
    ll aij, sum = 0;
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            cin >> aij;
            if (i == j)
                sum += aij;
        }
    }
    ans = double(sum)/double(n);
    return ans;
}

int main()
{
    cin >> n;
    cout << setprecision(2) << fixed << MainDiagAvg();
    return 0;
}
