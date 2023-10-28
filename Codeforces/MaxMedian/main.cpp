#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n, k, a[MaxN+1], ForSort[MaxN+1];
map<int, int> ma;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        ForSort[i] = a[i];
    }
}

bool Check(int val, int k) {
    vector<int> B(n+1, 0);
    vector<int> Min(n+1, 1e9);
    for (int i=1; i<=n; i++)
        if (a[i] < val)
            B[i] = -1;
        else
            B[i] = 1;
    int MinB = 0, MinBId = 0;
    Min[0] = 0;
    for (int i=1; i<=n; i++) {
        B[i] = B[i-1] + B[i];
        Min[i] = min(Min[i-1], B[i]);
    }
    for (int i=k; i<=n; i++)
        if (B[i] - Min[i-k] > 0)
            return true;
    return false;
}

int Solution() {
    sort(ForSort+1, ForSort+1+n);
    int lo = 1, hi = n, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if (Check(ForSort[mid], k)) {
            ans = ForSort[mid];
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    cout << Solution();
    return 0;
}
