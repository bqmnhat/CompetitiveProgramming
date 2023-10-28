#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int n;
bool mark[MaxN+1];

int Solution() {
    for (int i=1; i<n; i++) {
        int ai;
        cin >> ai;
        mark[ai] = true;
    }
    for (int i=1; i<=n; i++)
        if (!mark[i])
            return i;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << Solution();
    return 0;
}
