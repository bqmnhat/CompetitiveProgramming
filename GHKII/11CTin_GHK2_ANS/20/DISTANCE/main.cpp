#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d;
double x, y, z;
double khoangcach;

int main()
{
    freopen("DISTANCE.inp", "r", stdin);
    freopen("DISTANCE.out", "w", stdout);
    cin >>  n;
    cin >> a >> b;
    khoangcach = 0;
    x = abs(a-b);
    for (int i = 0; i < n; i++){
        cin >> c >> d;
        y = abs(c-d);
        z = sqrt(abs(x-y));
        if (z >= khoangcach){
            khoangcach = z;
        }
    }
    cout << setprecision(4) << fixed << khoangcach;
    return 0;
}
