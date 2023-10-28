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

double CalDist(pdd a, pdd b) {
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

double CalAns(const vector<pdd>& a) {
    pdd FirstVector = pdd(a[0].first - 0.0, a[0].second - 0.0);
    pdd SecondVector = pdd(a[1].first - 0.0, a[1].second - 0.0);
    double Tu = abs((FirstVector.first * SecondVector.first) + (FirstVector.second * SecondVector.second));
    double FirstLen = sqrt((FirstVector.first*FirstVector.first) + (FirstVector.second*FirstVector.second));
    double SecondLen = sqrt((SecondVector.first*SecondVector.first) + (SecondVector.second*SecondVector.second));
    double Mau = FirstLen*SecondLen;
    double ans = Tu/Mau;
    return ans;
}

void Solve() {
    double MinDist = 1e15+1;
    vector<pdd> ClosestPairs(2);
    for (int i=1; i<n; i++) {
        for (int j=i+1; j<=n; j++) {
            double tmp = CalDist(Points[i], Points[j]);
            if (tmp < MinDist) {
                MinDist = tmp;
                ClosestPairs[0] = Points[i];
                ClosestPairs[1] = Points[j];
            }
        }
    }
    double ans = CalAns(ClosestPairs);
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
