#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n;

int AskingQuery(int l, int r) {
    if (l >= r)
        return -1;
    int tmp;
    cout << "? " << l << ' ' << r << endl;
    cin >> tmp;
    return tmp;
}

int LeftSol(int lo, int hi, int SecMax)  {
    int mid;
    while (lo < hi-1) {
        mid = (lo + hi)/2;
        int tmp = AskingQuery(mid, SecMax);
        if (tmp == SecMax)
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int RightSol(int lo, int hi, int SecMax)  {
    int mid;
    while (lo < hi-1) {
        mid = (lo + hi)/2;
        int tmp = AskingQuery(SecMax, mid);
        if (tmp == SecMax)
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

int Solution() {
    int SecMax = AskingQuery(1, n);
    int tmp = AskingQuery(1, SecMax);
    if ((tmp != SecMax) || (SecMax == 1))
        return RightSol(SecMax, n, SecMax);
    else
        return LeftSol(1, SecMax, SecMax);
}

void Solve() {
    int ans = Solution();
    cout << "! " << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Solve();
    return 0;
}
