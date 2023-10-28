#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,l,r,x,c[16];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> c[i];
}

bool Check(int k) {
    int sum = 0, Min = 1e9, Max = 0, i = 1, NumOfId = 0;
    while (k > 0) {
        int tmp = k%2;
        if (tmp == 1) {
            sum += c[i];
            Min = min(Min, c[i]);
            Max = max(Max, c[i]);
            NumOfId++;
        }
        k = (k >> 1);
        i++;
    }
    return ((NumOfId >= 2) && (sum >= l) && (sum <= r) && (Max - Min >= x));
}

int Solution() {
    int ans = 0;
    for (int i=1; i<= (1 << n); i++)
        if (Check(i))
            ans++;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> r >> x;
    ReadData();
    cout << Solution();
    return 0;
}
