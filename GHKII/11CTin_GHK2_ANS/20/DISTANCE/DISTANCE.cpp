#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d;
double x, y, z;
double khoangcach;

int main()
{
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
    cout << khoangcach;
    return 0;
}
