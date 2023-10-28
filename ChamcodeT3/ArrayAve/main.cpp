#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

double Average() {
    ll sum = 0, ai;
    double ans;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        sum += ai;
    }
    ans = double(sum)/double(n);
    return ans;
}

int main()
{
    cin >> n;
    cout << fixed << setprecision(2) << Average();
    return 0;
}
