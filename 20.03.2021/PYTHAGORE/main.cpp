#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long tri[5001];
int p, t;

bool IsCP(int x) {
    int m = sqrt(x);
    return (m*m == x);
}

void CountP() {
    for (int a=3; a<5000; a++) {
        for (int b=a+1; b<5000-a; b++) {
            int m = a*a + b*b;
            if (IsCP(m) == true) {
                int c = sqrt(m);
                int cv = a+b+c;
                if (cv <= 5000)
                    tri[cv]++;
            }
        }
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> p;
        cout << tri[p] << endl;
    }
}

int main()
{
    freopen("PYTHAGORE.INP", "r", stdin);
    freopen("PYTHAGORE.OUT", "w", stdout);
    cin >> t;
    CountP();
    Solve();
    return 0;
}
