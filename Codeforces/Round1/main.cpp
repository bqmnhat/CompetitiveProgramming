#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Round1.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n % 4 == 0) {
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
    }
    return 0;
}
