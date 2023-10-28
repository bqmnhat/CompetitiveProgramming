#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, L, R, f1[100002], f2[100002];
pair<int,int> robot[100001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> robot[i].first >> robot[i].second;
}

int Solution() {
    int ans = 0;
    sort(robot+1, robot+1+n);
    f1[1] = robot[1].second;
    for (int i = 2; i<=n; i++)
        f1[i] = max(f1[i-1], robot[i].second);
    f2[n+1] = R;
    for (int i=n; i>=1; i--) {
        f2[i] = f2[i+1];
        if (robot[i].second >= f2[i+1])
            f2[i] = robot[i].first;
    }
    for (int i=1; i<=n; i++) {
        if ((robot[i].first > R) || (robot[i].second < L))
            ans = max(ans, robot[i].second - robot[i].first);
        else if ((i == 1) && (f2[i+1] <= L))
            ans = max(ans, robot[i].second - robot[i].first);
        else if ((i == n) && (f1[i-1] >= R))
            ans = max(ans, robot[n].second - robot[n].first);
        else if (f1[i-1] >= f2[i+1])
            ans = max(ans, robot[i].second - robot[i].first);
    }
    return ans;
}

int main()
{
    cin >> n >> L >> R;
    ReadData();
    cout << Solution();
    return 0;
}
