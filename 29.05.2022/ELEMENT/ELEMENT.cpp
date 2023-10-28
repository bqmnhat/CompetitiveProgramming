#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
typedef pair<int, int> pii;
int n, a[MaxN+1], ma[500001], Base = 200000;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void MakeSumMap() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int sum = a[i] + a[j] + Base;
            if (ma[sum] == 0)
                ma[sum] = max(i, j);
            else
                ma[sum] = min(ma[sum], max(i, j));
        }
    }
}

int Solution() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        bool Found = false;
        for (int j=1; j<i; j++) {
            int tmp = a[i] - a[j];
            if ((ma[tmp + Base] != 0) && (ma[tmp + Base] < i)) {
                Found = true;
                break;
            }
        }
        if (Found)
            ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ELEMENT.INP", "r", stdin);
    freopen("ELEMENT.OUT", "w", stdout);
    cin >> n;
    ReadData();
    MakeSumMap();
    cout << Solution();
    return 0;
}
