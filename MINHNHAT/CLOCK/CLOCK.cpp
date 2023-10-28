#include <iostream>
#include <cstdio>
using namespace std;

void Solve(int h, int p, int s) {
    s = s + 1;
    if (s == 60) {
        s = 0;
        p = p + 1;
    }
    if (p == 60) {
        p = 0;
        h = h + 1;
    }
    if (h == 24) {
        h = 0;
    }
    cout << h << " " << p << " " << s;
}

int main()
{
    int h,p,s;
    freopen("CLOCK.INP", "r", stdin);
    freopen("CLOCK.OUT", "w", stdout);
    cin >> h >> p >> s;
    Solve(h,p,s);
    return 0;
}
