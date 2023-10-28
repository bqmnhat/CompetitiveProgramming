#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n1,n2;

int LengthOfN(int n) {
    int ans = 0;
    while (n > 0) {
        n = n/10;
        ans = ans + 1;
    }
    return ans;
}

void Gen(int n1, int n2) {
    if (n1 <= 9) {
        int m = min(9,n2);
        for (int i = n1; i<=m; i++)
            cout << i << endl;
        n1 = 10;
    }
    int i = 0, a = 0, t = 0, l2 = LengthOfN(n2), d = LengthOfN(n1);
    while (true) {
        if ((a >= n1) && (a <= n2) && (i == d)) {
            cout << a << endl;
            t = a%10;
            a = a/10;
            i = i - 1;
        }
        t = t + 1;
        if ((t <= 9) && (a*10 + t <= n2) && (i < d)) {
            a = a * 10 + t;
            i = i + 1;
            t = t - 1;
        }
        else {
            t = a%10;
            a = a/10;
            if (i > 0)
                i = i - 1;
            if ((t == 9) && (a == 0) && (l2 > d)) {
                d = d + 1;
                t = 0;
                continue;
            }
        }
        if ((t == 0) && (a == 0) && (d == l2))
            return;
    }
}

int main()
{
    freopen("STEP.INP", "r", stdin);
    freopen("STEP.OUT", "w", stdout);
    cin >> n1 >> n2;
    Gen(n1,n2);
    return 0;
}
