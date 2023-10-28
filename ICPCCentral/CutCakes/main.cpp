#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Point {
    long long x,y;
} a,b,c;

struct Segment {
    Point A,B,len;
}ab, ac, bc;

double AreaDaiSo(Point A, Point B, Point C) {
    double ans = (double(B.y + A.y)*double(B.x - A.x)/2.00) + (double(A.y + C.y)*double(A.x - C.x)/2.00) + (double(B.y + C.y)*double(B.x - C.x)/2.00);
    return ans;
}

double Area() {
    long long p = (ab.len + ac.len + bc.len)/2;
    double ans = sqrt(p*(p-ab.len)*(p-ac.len)*(p-bc.len));
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
