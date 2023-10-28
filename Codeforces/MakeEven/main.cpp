#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, digits[10], ld = 0;
bool IsEven = false;

void SplitData(int x) {
    while (x > 0) {
        ld++;
        digits[ld] = x%10;
        if (digits[ld]%2 == 0)
            IsEven = true;
        x = x/10;
    }
}

int Solution() {
    if (n%2 == 0)
        return 0;
    if (digits[ld]%2 == 0)
        return 1;
    if (IsEven)
        return 2;
    else
        return -1;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ld = 0;
        IsEven = false;
        SplitData(n);
        cout << Solution() << '\n';
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
