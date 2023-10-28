#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool a[25000001];
int t,n;

void MakeSieve() {
    int m = sqrt(25000000);
    a[0] = a[1] = true;
    for (int i = 2; i<=m; i++) {
        if (a[i] == false) {
            for (int j = i; j<=25000000/i; j++) {
                a[i*j] = true;
            }
        }
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        int x = n,y = n;
        if (a[n] == false) {
            while (a[x] == true) {
                x++;
            }
            while (a[y] == true) {
                y--;
            }
            if (((x+y)%2 == 0) && ((x+y)/2 == n)) {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }
}

int main()
{
    freopen("SYMPRIME.INP", "r", stdin);
    freopen("SYMPRIME.OUT", "w", stdout);
    MakeSieve();
    cin >> t;
    Solve();
    return 0;
}
