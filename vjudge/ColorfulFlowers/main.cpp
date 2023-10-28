#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a, b, c;
const double pi = acos(-1);

double AreaHeron(int a, int b, int c) {
    double p = double(a+b+c)/2.0;
    double ans = sqrt(p*(p-double(a))*(p-double(b))*(p - double(c)));
    return ans;
}

void SolveTestCase() {
    double TriArea = AreaHeron(a, b, c);
    double p = double(a+b+c)/2.0;
    double r = TriArea/p;
    double RedArea = pi*(r*r);
    double BlueArea = TriArea - RedArea;
    double R = double(a*b*c)/(TriArea*4.0);
    double YellowCircle = pi*(R*R);
    double YellowArea = YellowCircle - TriArea;
    cout << setprecision(4) << fixed << YellowArea << ' ' << BlueArea << ' ' << RedArea << '\n';
}

void Solve() {
    while (cin >> a >> b >> c)
        SolveTestCase();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
