#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Point {
    double x,y;
} a,b,c;

struct Segment {
    Point A,B;
};

double Area(Point A, Point B, Point C) {
    double ans = (B.y + A.y)*(B.x - A.x)/2 + (A.y + C.y)*(A.x - C.x)/2 + (B.y + C.y)*(B.x - C.x)/2;
    return ans;
}

int main()
{
    a.x = 1;
    a.y = 1;
    b.x = 1;
    b.y = 4;
    c.x = 5;
    c.y = 1;
    cout << Area(b,c,a);
    return 0;
}
