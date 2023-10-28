#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int n;
bool mark[MaxN+5];

void Solve() {
    int cnt = 0, i = 0;
    while (cnt < n) {
        do {
            i = (i+1)%n;
            if (i == 0)
                i = n;
        } while (mark[i]);
        do {
            i = (i+1)%n;
            if (i == 0)
                i = n;
        } while (mark[i]);
        mark[i] = true;
        cout << i << ' ';
        cnt++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Solve();
    return 0;
}
