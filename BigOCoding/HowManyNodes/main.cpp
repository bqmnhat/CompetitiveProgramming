#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, c[19] = {1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190};

void Solve() {
    while (cin >> n) {
        for (int i=0; i<19; i++) {
            if (c[i] == n) {
                cout << i+1 << '\n';
                break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
