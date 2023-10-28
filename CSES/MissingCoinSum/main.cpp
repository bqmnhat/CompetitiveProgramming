#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n;
ll x[MaxN+1], pref[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> x[i];
        pref[i] = pref[i-1] + x[i];
    }
}

bool BinSearchOnPref(int lo, int hi, int id, ll val) {
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        if (pref[mid] - pref[id-1] >= val)

        else if (pref[mid] - pref[id-1] < val)
            lo = mid + 1;
        else
            return true;
    }
    return false;
}

ll Solution() {
    ll ans = 0;
    int lo = 1, hi = 1e9;
    while (lo <= hi) {

    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
