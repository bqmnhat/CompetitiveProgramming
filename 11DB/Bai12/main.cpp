#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const double MileToKmScale = 1.609344;
double InKm;

int main()
{
    cout << "Input distance (km): ";
    cin >> InKm;
    double ans = InKm * MileToKmScale;
    cout << "Distance (Mile): " << fixed << setprecision(6) << ans;
    return 0;
}
