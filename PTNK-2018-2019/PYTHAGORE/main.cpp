#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
long long tri[5001];

bool IsCP(int x) {
    int m = sqrt(x);
    return (m*m == x);
}

void CountTri() {
    for (int a=3; a<5000; a++) {
        for (int b = a+1; b<5000-a; b++) {
            int m = a*a + b*b;
            int c = sqrt(m);
            if ((IsCP(m) == true) && (a+b+c <= 5000)) {
                tri[a+b+c]++;
            }
        }
    }
}

void Solve() {
    int p;
    for (int i=1; i<=t; i++) {
        cin >> p;
        cout << tri[p] << endl;
    }
}

int main()
{
    freopen("PYTHAGORE.INP", "r", stdin);
    freopen("PYTHAGORE.OUT", "w", stdout);
    CountTri();
    cin >> t;
    Solve();
    return 0;
}

