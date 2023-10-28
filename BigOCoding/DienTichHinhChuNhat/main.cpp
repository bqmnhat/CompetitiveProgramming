#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n, x1, yy1, x2, y2, MinX[30001], MaxX[30001];

void Init() {
    for (int i=0; i<=30000; i++) {
        MinX[i] = 1e9;
        MaxX[i] = -1;
    }
}

long long Solution() {
    for (int i=1; i<=n; i++) {
        cin >> x1 >> yy1 >> x2 >> y2;
        for (int i=yy1; i<y2; i++) {
            MinX[i] = min(MinX[i], x1);
            MaxX[i] = max(MaxX[i], x2);
        }
    }
    long long ans = 0;
    for (int i=0; i<=30000; i++)
        if ((MinX[i] != 1e9) && (MaxX[i] != -1))
            ans += (MaxX[i] - MinX[i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Init();
    cout << Solution();
    return 0;
}
