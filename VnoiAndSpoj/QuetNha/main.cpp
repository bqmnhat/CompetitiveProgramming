#include <iostream>
#include <bits/stdc++.h>
#define MaxN 92
using namespace std;
typedef unsigned long long ull;
ull x, y;

ull Solution() {
    ull cnt = 0;
    while ((x > 0) && (y > 0)) {
        if (x <= y) {
            cnt += y/x;
            y %= x;
        }
        else {
            cnt += x/y;
            x %= y;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> y;
    cout << Solution();
    return 0;
}
