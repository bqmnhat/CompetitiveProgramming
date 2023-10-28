#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, W, w[81], v[81], MaxVal = 0;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> w[i] >> v[i];
}

void BackTracking(int CurVal, int CurWei, int i) {
    if ((CurWei > W) || (i > n))
        return;
    if (CurVal > MaxVal)
        MaxVal = CurVal;
    BackTracking(CurVal, CurWei, i + 1);
    BackTracking(CurVal+v[i+1], CurWei + w[i+1], i + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> W;
    ReadData();
    BackTracking(0, 0, 0);
    cout << MaxVal;
    return 0;
}
