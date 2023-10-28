#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, t;

bool IsPrime(int val) {
    if (val <= 1)
        return false;
    for (int i=2; i*i<=val; i++)
        if (val%i == 0)
            return false;
    return true;
}

void SolveTestCase() {
    if (n == 1)
        cout <<"FastestFinger" << '\n';
    else if (n == 2)
        cout <<"Ashishgup" << '\n';
    else if (n&1)
        cout << "Ashishgup" << '\n';
    else {
        int cntPow2 = 0, tmpn = n;
        while (tmpn%2 == 0) {
            cntPow2++;
            tmpn >>= 1;
        }
        if (tmpn == 1)
            cout <<"FastestFinger" << '\n';
        else if (cntPow2 == 1) {
            if (IsPrime(tmpn))
                cout << "FastestFinger" << '\n';
            else
                cout <<"Ashishgup" << '\n';
        }
        else
            cout <<"Ashishgup" << '\n';
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
