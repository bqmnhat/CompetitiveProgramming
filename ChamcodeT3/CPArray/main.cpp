#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

bool IsCP(ll val) {
    return ((sqrt(val)*sqrt(val)) == val);
}

void Solve() {
    ll ai;
    bool exist = false;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        if (IsCP(ai)) {
            if (!exist) {
                cout << ai;
                exist = true;
            }
            else
                cout << " " << ai;
        }
    }
    if (!exist)
        cout << "NOT FOUND";
}

int main()
{
    cin >> n;
    Solve();
    return 0;
}
