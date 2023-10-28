#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("DISTANCE.INP", "r", stdin);
    freopen("DISTANCE.OUT", "w", stdout);

    double n, a, b, c, d, x, y, z;
    double minimum = 0;
    cin >> n >> a >> b;
    x = abs(a - b);
    for(int i = 0; i < n; i++){
        cin >> c >> d;
        y = abs(c - d);
        z = sqrt(abs(x - y));
        if(z > minimum){
            minimum = z;
        }
    }
    cout << setprecision(5) << minimum;
}
