#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef pair<double, double> pdd;
pdd Points[MaxN+1];
int n;

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

double CalAns(const vector<pdd>& a) {
    pdd FirstVector = pdd(a[0].first - 0, a[0].second - 0);
    pdd SecondVector = pdd(a[1].first - 0, a[1].second - 0);
    double Tu = (FirstVector.first * SecondVector.first) + (FirstVector.second * SecondVector.second);
    double FirstLen = sqrt((FirstVector.first*FirstVector.first) + (FirstVector.second*FirstVector.second));
    double SecondLen = sqrt((SecondVector.first*SecondVector.first) + (SecondVector.second*SecondVector.second));
    double Mau = FirstLen + SecondLen;
    double ans = Tu/Mau;
    return ans;
}

vector<pdd> TrippleCmp(int lo, int hi, double& MinDist) {
    vector<pdd> ans(2);
    for (int i=lo; i<=hi; i++) {
        for (int j=lo; j<=hi; j++) {
            if (i == j)
                continue;
            double Dist = CalDist(Points[i], Points[j]);
            if (Dist < MinDist) {
                MinDist = Dist;
                ans[0] = Points[i];
                ans[1] = Points[j];
            }
        }
    }
    return ans;
}

vector<pdd> StripCmp(vector<pdd>& strip, double& MinDist) {
    vector<pdd> ans(2);
    sort(strip.begin(), strip.end(), CmpPointsY);
    int len = strip.size();
    for (int i=0; i<len; i++) {
        for (int j=i+1; (j<len)&&(strip[j].second - strip[i].second < MinDist); j++) {
            double tmpD = CalDist(strip[i], strip[j]);
            if (tmpD < MinDist) {
                ans[0] = strip[i];
                ans[1] = strip[j];
                MinDist = tmpD;
            }
        }
    }
    return ans;
}

vector<pdd> ClosestPairs(int lo, int hi, double& MinDist) {
    vector<pdd> cpSeg(2), cp1(2), cp2(2);
    if (hi - lo + 1 <= 3)
        return TrippleCmp(lo, hi, MinDist);
    int mid = (lo + hi)/2;
    double MinDist1 = 1e18 + 1, MinDist2 = 1e18 + 1;
    cp1 = ClosestPairs(lo, mid, MinDist1);
    cp2 = ClosestPairs(mid+1, hi, MinDist2);
    MinDist = min(MinDist1, MinDist2);
    if (MinDist1 < MinDist2)
        cpSeg = cp1;
    else
        cpSeg = cp2;
    vector<pdd> strips;
    for (int i = lo; i<=hi; i++)
        if (abs(Points[i].first - Points[mid].first) <= MinDist)
            strips.push_back(Points[i]);
    double StripMinDist = MinDist;
    vector<pdd> StripAns = StripCmp(strips, StripMinDist);
    if (StripMinDist < MinDist) {
        MinDist = StripMinDist;
       cpSeg = StripAns;
    }
    return cpSeg;
}

void Solve() {
    sort(Points+1, Points + 1 + n, CmpPointsX);
    double MinDist = 1e18 + 1;
    vector<pdd> Cp = ClosestPairs(1, n, MinDist);
    double ans = CalAns(Cp);
    cout << fixed << setprecision(4) << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
