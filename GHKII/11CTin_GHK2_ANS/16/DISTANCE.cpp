#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ld, ld> pdd;
const ld EPS = 1e-9;

bool cmp(ld x, ld y) {
    return (x < y - EPS)? -1 : (x > y + EPS);
}

struct Point {
    ld x, y;
    Point(ld _x = 0, ld _y = 0) : x(_x), y(_y) {};

    ld Norm() {
        return x*x + y*y;
    }

    ld len() {
        return sqrt(Norm());
    }

    ld dot(Point A) {
        return ((this->x)*A.x + (this->y)*A.y);
    }
};

struct Line {
    ld a, b, c;
    Line(Point A, Point B) {
        Point n = Point(B.y - A.y, -(B.x - A.x));
        a = n.x;
        b = n.y;
        c = -n.x*A.x - n.y*A.y;
    }

    Line(Point A, ld _a, ld _b) {
        a = _a;
        b = _b;
        c = -a*A.x - b*A.y;
    }

    ld PointWLine(Point A) {
        return (a*A.x + b*A.y + c);
    }
};

Point operator +(Point A, Point B) {
    return Point(A.x + B.x, A.y + B.y);
}

Point operator -(Point A, Point B) {
    return Point(A.x - B.x, A.y - B.y);
}

Point operator *(Point A, ld k) {
    return Point(A.x*k, A.y*k);
}

ld DistPointToPoint(Point A, Point B) {
    return (B - A).len();
}

Point Disect(Line d1, Line d2) {
    ld d = d1.a*d2.b - d1.b*d2.a;
    ld dx = d1.b*d2.c - d1.c*d2.b;
    ld dy = d1.c*d2.a - d1.a*d2.c;
    Point ans = Point((dx / d), (dy / d));
    return ans;
}

ld DistToLine(Point P, Point A, Point B, Point& C) {
    Line d(A, B);
    Point n = Point(d.a, d.b);
    Point nOfP = Point(n.y, -n.x);
    Line dP(P, nOfP.x, nOfP.y);
    C = Disect(dP, d);
    ld ans = abs(d.PointWLine(P))/sqrt(d.a*d.a + d.b*d.b);
    return ans;
}

bool IsInSeg(Point P, Point A, Point B) {
    return ((min(A.x, B.x) <= P.x) && (P.x <= max(A.x, B.x)) && (min(B.y, A.y) <= P.y) && (P.y <= max(A.y, B.y)));
}

ld DistToSeg(Point P, Point A, Point B) {
    Point tmp;
    ld Dist = DistToLine(P, A, B, tmp);
    if (IsInSeg(tmp, A, B))
        return Dist;
    else
        return min(DistPointToPoint(P, B), DistPointToPoint(P, A));
}

int n;
Point a[MaxN+5], p;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].x >> a[i].y;
}

ld Solution() {
    ld ans = 1e18;
    for (int i=1; i<=n; i++) {
        ld Dist = DistToSeg(p, a[i], a[i%n+1]);
        ans = min(ans, Dist);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DISTANCE.INP", "r", stdin);
    freopen("DISTANCE.OUT", "w", stdout);
    cin >> n >> p.x >> p.y;
    ReadData();
    cout << fixed << setprecision(4) << Solution();
    return 0;
}
