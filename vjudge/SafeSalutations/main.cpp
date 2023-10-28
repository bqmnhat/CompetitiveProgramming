#include <iostream>
#include <bits/stdc++.h>
#define MaxN 11
using namespace std;
int n, a[MaxN+1] = {0, 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cnt = 0;
    while (cin >> n) {
        cnt++;
        if (cnt > 1)
            cout << '\n';
        cout << a[n+1] << '\n';
    }
    return 0;
}
