#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, cntOdd = 0, cntEven = 0;

void ReadData() {
    int ai;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        if (ai%2 == 0)
            cntEven++;
        else
            cntOdd++;
    }
}

int Solution() {
    int Pairs = min(cntOdd, cntEven);
    cntOdd -= Pairs;
    cntEven -= Pairs;
    if (cntOdd > 0)
        Pairs += (cntOdd/2);
    return Pairs;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
