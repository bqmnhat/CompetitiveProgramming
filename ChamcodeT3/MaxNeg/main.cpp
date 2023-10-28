#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

void Solve() {
    ll Max = -9e18, ai;
    bool exist = false;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        if ((ai > Max) && (ai < 0)) {
            exist = true;
            Max = ai;
        }
    }
    if (!exist)
        cout << "NOT FOUND";
    else
        cout << Max;
}

int main()
{
    cin >> n;
    Solve();
    return 0;
}
