#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, x[1001], y[1001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i] >> y[i];
}

double AverageDistance(int k) {
    double ans = 0;
    for (int i=1; i<=n; i++) {
        if (k != i)
            ans += abs(x[i] - x[k]) + abs(y[i] - y[k]);
    }
    return (ans/double(n));
}

void Solve() {
    double MinDist = 3e9;
    int MinID = 0;
    for (int i=1; i<=n; i++) {
        double tmp = AverageDistance(i);
        if (tmp < MinDist) {
            MinDist = tmp;
            MinID = i;
        }
        else if (tmp == MinDist) {
            if (x[i] == x[MinID]) {
                if (y[i] < y[MinID]) {
                    MinDist = tmp;
                    MinID = i;
                }
            }
            else if (x[i] < x[MinID]) {
                MinDist = tmp;
                MinID = i;
            }
        }
    }
    cout << x[MinID] << " " << y[MinID];
}

int main()
{
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
