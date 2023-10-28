#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k;

int DFS(int n) {
    if (n <= k)
        return 1;
    int gr1 = (n - k)/2, gr2 = n - gr1, ans = 0;
    if (abs(gr1 - gr2) == k)
        ans += DFS(gr1) + DFS(gr2);
    else
        ans = 1;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    cout << DFS(n);
    return 0;
}
