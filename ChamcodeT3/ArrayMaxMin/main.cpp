#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

void Solve() {
    ll Max = 0, Min = 1e18, ai;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        if (ai > Max)
            Max = ai;
        if (ai < Min)
            Min = ai;
    }
    cout << Max << " " << Min;
}

int main()
{
    cin >> n;
    Solve();
    return 0;
}
