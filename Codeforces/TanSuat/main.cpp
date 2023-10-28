#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
ll a[MaxN+1], pref[MaxN+1], k;
ld MinEquation[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
}

bool Check(ld T) {
    // Check if for each i exist a j (j <= i - k + 1) that p[j-1] - t*j <= p[i] - T*i - T (1*)
    // equation = p[i] - T*(i+1.0)
    MinEquation[0] = 1e18;
    for (int i=1; i<=n; i++) {
        ld tmp = ld(pref[i-1]) - T*ld(i);
        MinEquation[i] = min(MinEquation[i-1], tmp);
    }
    for (int i=k; i<=n; i++) {
        ld Tmp = ld(pref[i]) - T*(ld(i)+1.0); // The right hand side part
        if (Tmp >= MinEquation[i - k + 1]) // Any others Equation from 1 => i - k + 1 will be larger than MinEuqation[i-k+1] so if MinEquation[i-k+1] satisfy criteria (1*) then the (1*) will satisfy
            return true;
    }
    return false;
}

ld Solution() {
    ld lo = 0.0, hi = 1e12, Err = 1e-6;
    while (hi - lo > Err) {
        ld mid = ((lo + hi)/2.0);
        if (Check(mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    cout << fixed << setprecision(2) << Solution();
    return 0;
}
