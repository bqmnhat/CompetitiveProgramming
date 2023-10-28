#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 10000000
int n;
bool tk[MaxN+2];

void ReadData() {
    int ai;
    for (int i = 1; i<=n; i++) {
        cin >> ai;
        if (ai <= MaxN)
            tk[ai] = true;
    }
}

int FindMin() {
    int Min = 1;
    while (tk[Min])
        Min++;
    return Min;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("KMIN.INP", "r", stdin);
    freopen("KMIN.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << FindMin();
    return 0;
}
