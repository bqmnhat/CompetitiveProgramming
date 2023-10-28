#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000000
using namespace std;
typedef long long ll;
int n, k, spTabMax[MaxN+1][25], spTabMin[MaxN+1][25], log_2[MaxN+1];

void ReadData() {
    for (int i=0; i<n; i++) {
        cin >> spTabMax[i][0];
        spTabMin[i][0] = spTabMax[i][0];
    }
}

void CalLog2() {
    log_2[0] = log_2[1] = 0;
    for (int i=2; i<=MaxN; i++)
        log_2[i] = log_2[i/2] + 1;
}

void SpTabCalculation() {
    int step;
    for (int j=1; (1 << j) <= n; j++) {
        step = (1 << (j-1));
        for (int i=0; i + 2*step <= n; i++)
            spTabMin[i][j] = min(spTabMin[i][j-1], spTabMin[i + step][j-1]);
    }
    for (int j=1; (1 << j) <= n; j++) {
        step = (1 << (j-1));
        for (int i=0; i + 2*step <= n; i++)
            spTabMax[i][j] = max(spTabMax[i][j-1], spTabMax[i + step][j-1]);
    }
}

int MaxQuery(int l, int r) {
    int k = log_2[r-l+1];
    return max(spTabMax[l][k], spTabMax[r - (1 << k) + 1][k]);
}

int MinQuery(int l, int r) {
    int k = log_2[r-l+1];
    return min(spTabMin[l][k], spTabMin[r - (1 << k) + 1][k]);
}

/*bool Check(int len) {
    for (int i=1; i+len-1<=n; i++)
        if (MaxQuery(i, i+len-1) - MinQuery(i, i+len-1) <= k)
            return true;
    return false;
}*/

int Solution() {
    int ans = 1;
    for (int i=0; i<n; i++) {
        int lo = i, hi = n-1, tmped;
        while (lo <= hi) {
            int mid = (lo + hi)/2;
            if (MaxQuery(i, mid) - MinQuery(i, mid) <= k) {
                tmped = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        ans = max(ans, tmped - i + 1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    CalLog2();
    ReadData();
    SpTabCalculation();
    cout << Solution();
    return 0;
}
