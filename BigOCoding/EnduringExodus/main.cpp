#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k;
string s;

int NextEmptySpace(int x) {
    do {
        x++;
    } while ((x < n) && (s[x] == '1'));
    return x;
}

int Solution() {
    int lo = NextEmptySpace(-1), mid = lo, hi = lo, ans = 1e9;
    for (int i=1; i<=k; i++)
        hi = NextEmptySpace(hi);
    while (hi < n) {
        int NextM = NextEmptySpace(mid);
        while (max(mid - lo, hi - mid) > max(NextM - lo, hi - NextM)) {
            mid = NextM;
            NextM = NextEmptySpace(mid);
        }
        ans = min(ans, max(mid - lo, hi - mid));
        lo = NextEmptySpace(lo);
        hi = NextEmptySpace(hi);
    }
    return ans;
}

int main()
{
    cin >> n >> k >> s;
    cout << Solution();
    return 0;
}
