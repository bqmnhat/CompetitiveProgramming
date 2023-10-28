#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[10000001], la = 0;

void Solve() {
    ll ai;
    bool exi = false;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        if (ai > 0) {
            if (!exi) {
                exi = true;
                cout << ai;
            }
            else
                cout << " " << ai;
        }
        else if (ai < 0){
            la++;
            a[la] = ai;
        }
    }
    if (!exi)
        cout << "NOT FOUND";
    cout << '\n';
    if (la == 0)
        cout << "NOT FOUND";
    else {
        cout << a[1];
        for (int i=2; i<=la; i++)
            cout << " " << a[i];
    }
}

int main()
{
    cin >> n;
    Solve();
    return 0;
}
