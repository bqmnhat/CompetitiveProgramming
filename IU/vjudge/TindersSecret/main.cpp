#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef pair<double, double> pdd;
int n;
pdd Points[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> Points[i].first >> Points[i].second;
}

bool CmpPointsX(pdd a, pdd b) {
    return (a.first < b.first);
}

bool CmpPointsY(pdd a, pdd b) {
    return (a.second < b.second);
}

double CalDist(pdd a, pdd b) {
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

vector<double> Among3Points(pdd Points[], double& MinDist, int lo, int hi) {
    vector<double> ans(4, 0);
    for (int i=lo; i<=hi; i++) {
        for (int j=lo; j<=hi; j++) {
            if (i == j)
                continue;
            double tmpD = CalDist(Points[i], Points[j]);
            if (tmpD < MinDist) {
                ans[0] = Points[i].first;
                ans[1] = Points[i].second;
                ans[2] = Points[j].first;
                ans[3] = Points[j].second;
                MinDist = tmpD;
            }
        }
    }
    return ans;
}

vector<double> ClosestPairStrip(vector<pdd>& strip, double& MinDist) {
    vector<double> ans(4, 0);
    sort(strip.begin(), strip.end(), CmpPointsY);
    int l = strip.size();
    for (int i=0; i<l; i++) {
        for (int j=i+1; (j<l) && (strip[j].second - strip[i].second < MinDist); j++) {
            double tmpD = CalDist(strip[i], strip[j]);
            if (tmpD < MinDist) {
                ans[0] = strip[i].first;
                ans[1] = strip[i].second;
                ans[2] = strip[j].first;
                ans[3] = strip[j].second;
                MinDist = tmpD;
            }
        }
    }
    return ans;
}

vector<double> ClosestPair(pdd Points[], int lo, int hi, double& MinDist) {
    vector<double> ans(4, 0), ans1(4, 0), ans2(4, 0);
    if (hi - lo + 1 <= 3)
        return Among3Points(Points, MinDist, lo, hi);
    double MinDist1 = 1e9, MinDist2 = 1e9;
    int mid = (lo + hi)/2;
    ans1 = ClosestPair(Points, lo, mid, MinDist1);
    ans2 = ClosestPair(Points, mid+1, hi, MinDist2);
    if (MinDist1 < MinDist2)
        ans = ans1;
    else
        ans = ans2;
    MinDist = min(MinDist1, MinDist2);
    vector<pdd> strip;
    strip.clear();
    for (int i=lo; i<=hi; i++)
        if (abs(Points[i].first - Points[mid].first) < MinDist)
            strip.push_back(Points[i]);
    double StripMinDist = MinDist;
    vector<double> StripAns = ClosestPairStrip(strip, StripMinDist);
    if (StripMinDist < MinDist) {
        ans = StripAns;
        MinDist = StripMinDist;
    }
    return ans;
}

void SolveTestCase() {
    sort(Points+1, Points+1+n, CmpPointsX);
    double MinDist = 1e9;
    vector<double> Cp = ClosestPair(Points, 1, n, MinDist);
    cout << fixed << setprecision(2) << Cp[0] << ' ' << Cp[1] << ' ' << Cp[2] << ' ' << Cp[3] << '\n';
}

void Solve() {
    while ((cin >> n) && (n != 0)) {
        ReadData();
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
