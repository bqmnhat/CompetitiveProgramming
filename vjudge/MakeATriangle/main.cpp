#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a, b, c;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c;
    int ans = 1e9;
    if (a + b <= c)
        ans = min(ans, c - a - b + 1);
    if (a + c <= b)
        ans = min(ans, b - a - c + 1);
    if (b + c <= a)
        ans = min(ans, a - c - b + 1);
    if (ans == 1e9)
        ans = 0;
    cout << ans;
    return 0;
}
