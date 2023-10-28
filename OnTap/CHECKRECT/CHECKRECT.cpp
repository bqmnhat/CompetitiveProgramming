#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Point {
    long long x, y;
} a[5];

void ReadData() {
    for (int i=1; i<=4; i++)
        cin >> a[i].x >> a[i].y;
}

bool CmpX(Point a, Point b) {
    return (a.x < b.x);
}

bool CmpY(Point a, Point b) {
    return (a.y < b.y);
}

bool CheckRightAngle() {
    sort(a+1, a+1+4, CmpX);
    for (int i=1; i<=2; i++) {
        if (a[i*2].x == a[i*2-1].x) {
            if (a[i*2].y == a[i*2-1].y)
                return false;
        }
        else
            return false;
    }
    sort(a+1, a+1+4, CmpY);
    for (int i=1; i<=2; i++) {
        if (a[i*2].y == a[i*2-1].y) {
            if (a[i*2].x == a[i*2-1].x)
                return false;
        }
        else
            return false;
    }
    return true;
}

long long CheckSquare() {
    long long seg1 = abs(a[1].x - a[2].x), seg2 = abs(a[3].x - a[4].x), seg3 = abs(a[1].y - a[3].y), seg4 = abs(a[2].y - a[4].y);
    if ((seg1 == seg2) &&  (seg3 == seg4) && (CheckRightAngle() == true))
        return (a[1].x - a[2].x)*(a[2].y - a[4].y);
    else
        return -1;
}

int main()
{
    freopen("CHECKRECT.INP", "r", stdin);
    freopen("CHECKRECT.OUT", "w", stdout);
    ReadData();
    cout << CheckSquare();
    return 0;
}
