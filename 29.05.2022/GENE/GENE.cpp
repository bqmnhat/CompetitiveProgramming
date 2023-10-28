#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, SumNu[257], CorrectVal;
char Nu[5] = {' ', 'A', 'T', 'G', 'C'};
string s;

void CntATGC() {
    for (int i=0; i<n; i++)
        SumNu[s[i]]++;
}

bool Check(int len) {
    int SumNuOutRange[257], NuNeeded = 0;
    for (int i=1; i<=4; i++)
        SumNuOutRange[int(Nu[i])] = SumNu[int(Nu[i])];
    for (int i=0; i<len; i++)
        SumNuOutRange[s[i]]--;
    for (int i=1; i<=4; i++)
        NuNeeded += max(0, CorrectVal - SumNuOutRange[int(Nu[i])]);
    int i = 0, j = len-1;
    while ((i < n) && (j < n)) {
        if (NuNeeded <= len)
            return true;
        j++;
        SumNuOutRange[s[j]]--;
        SumNuOutRange[s[i]]++;
        i++;
        NuNeeded = 0;
        for (int i=1; i<=4; i++)
            NuNeeded += max(0, CorrectVal - SumNuOutRange[int(Nu[i])]);
    }
    return false;
}

int Solution() {
    int ans = -1, lo = 0, hi = n, mid;
    while (lo <= hi) {
        mid = (lo + hi)/2;
        if (Check(mid)) {
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("GENE.INP", "r", stdin);
    freopen("GENE.OUT", "w", stdout);
    cin >> n >> s;
    CorrectVal = n/4;
    CntATGC();
    cout << Solution();
    return 0;
}
