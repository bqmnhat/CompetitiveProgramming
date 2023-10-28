#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100010
using namespace std;
typedef pair<double, double> pdd;
int n;
pdd Segs[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> Segs[i].first >> Segs[i].second;
}

double Solution() {
    double Time = 0;
    for (int i=1; i<=n; i++)
        Time += (Segs[i].first/Segs[i].second);
    Time = Time/2.0;
    int i=0;
    double CurTime = 0, CurDist = 0;
    while (CurTime < Time) {
        i++;
        CurTime += (Segs[i].first/Segs[i].second);
        CurDist += Segs[i].first;
    }
    if (CurTime == Time)
        return CurDist;
    CurDist -= Segs[i].first;
    CurTime -= (Segs[i].first/Segs[i].second);
    double DeltaT = Time - CurTime;
    CurDist += DeltaT*Segs[i].second;
    return CurDist;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << fixed << setprecision(6) << Solution();
    return 0;
}
