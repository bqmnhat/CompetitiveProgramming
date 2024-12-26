#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, l, r, N = 20, R = 20;

int main()
{
    srand(time(0));
    freopen("SONDUONG.INP", "w", stdout);
    n = rand()% N;
    cout << n << '\n';
    for (int i=1; i<=n; i++) {
        int A = rand()%R;
        int B = rand()%R;
        if (A > B)
            swap(A, B);
        cout << A << ' ' << B << '\n';
    }
    return 0;
}
