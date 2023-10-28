#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef pair<int, int> pii;
int n, a[MaxN+1];
vector<int> LIS;
pii inp[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> inp[i].first >> inp[i].second;
}

void GetA() {
    sort(inp+1, inp+1+n);
    for (int i=1; i<=n; i++)
        a[i] = inp[i].second;
}

int Solution() {
    for (int i=n; i>=1; i--) {
        int j = upper_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
        if (j == LIS.size())
            LIS.push_back(a[i]);
        else
            LIS[j] = a[i];
    }
    return (LIS.size());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BOARD.INP", "r", stdin);
    freopen("BOARD.OUT", "w", stdout);
    cin >> n;
    ReadData();
    GetA();
    cout << Solution();
    return 0;
}
