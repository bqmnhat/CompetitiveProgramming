#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, dp[101];
struct Rec {
    int x1, y1, x2, y2, Area;
} a[101];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        a[i].Area = (abs(a[i].x1 - a[i].x2)) * (abs(a[i].y1 - a[i].y2));
    }
}

bool CmpArea(Rec a, Rec b) {
    return (a.Area < b.Area);
}

bool IsAInB(Rec a, Rec b) {
    bool ans = true;
    if ((a.x1 < b.x1) || (a.x2 > b.x2))
        ans = false;
    if ((a.y1 < b.y1) || (a.y2 > b .y2))
        ans = false;
    return ans;
}

int MaxConsecutive() {
    int ans = 1;
    dp[1] = 1;
    sort(a+1, a+1+n, CmpArea);
    for (int i=2; i<=n; i++) {
        int tmp = 0;
        for (int j=1; j<i; j++) {
            if ((IsAInB(a[j], a[i])) && (dp[j] > tmp)) {
                tmp = dp[j];
            }
        }
        dp[i] = tmp+1;
        if (dp[i] > ans)
            ans = dp[i];
    }
    return ans;
}

int main()
{
    freopen("NESTED.INP", "r", stdin);
    freopen("NESTED.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << MaxConsecutive();
    return 0;
}
