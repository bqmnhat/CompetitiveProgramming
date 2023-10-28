#include <iostream>
#include <bits/stdc++.h>
#define MaxN xxxxx
using namespace std;
typedef long double ld;
typedef long long ll;
const ld Pi = acos(-1);
const ld EPS = 1e-12;

int cmp(ld x, ld y) {
    return (x < y - EPS) ? -1 : (x > y + EPS);
}

struct Point {
    ld x, y;
    //constructor
    Point(ld _x = 0, ld _y = 0) : x(_x), y(_y) { }
    //Comparing point base on prioritizing x-axis value then y-axis value
    int cmp(const Point& q) const {
        if (x == q.x)
            return ::cmp(y, q.y);
        return ::cmp(x, q.x);
    }
    //defining operators
    #define op(x) bool operator x (const Point& q) const { return cmp(q) x 0; }
    op(>) op(<) op(==) op(>=) op(<=) op(!=)
    #undef op
    //vector sum
    Point operator + (const Point& q) const {
        return Point(x + q.x, y + q.y);
    }

    //vector sub
    Point operator - (const Point& q) const {
        return Point(x - q.x, y - q.y);
    }

    //vector Product w a num
    Point operator * (ld k) const {
        return Point(x*k, y*k);
    }

    //vector Quotient w a num
    Point operator / (ld k) const {
        return Point(x/k, y/k);
    }

    //dot product
    ld dot(const Point& q) const {
        return (x*q.x + y*q.y);
    }

    //cross product
    ld cross(const Point& q) const {
        return (x*q.y - y*q.x);
    }

    ld Norm() { //square of vector size
        return x*x + y*y;
    }

    ld len() {
        return sqrt(Norm());
    }

    Point Rotate(ld alpha) { // anti-clockwise
        ld cosa = cos(alpha), sina = sin(alpha);
        return Point(x*cosa - y*sina, x*sina + y*cosa);
    }
};

struct Line {
    ld a, b, c;
    Point A, B;
    //constructors
    //constructor base on a, b, c
    Line(ld a, ld b, ld c) : a(a), b(b), c(c) {}
    //constructor base on 2 Points A, B
    Line (Point A, Point B): A(A), B(B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = -(a*A.x + b*A.y);
    }
    //constructor base on 1 Point A and k
    Line(Point A, ld k) {
        a = -k;
        b = 1;
        c = k * A.x - A.y;
    }

    ld PointWLine(Point _A) {
        return (a*A.x + b*A.y + c);
    }
};

bool AreParallel(Line l1, Line l2) {
    return (cmp(l1.a*l2.b, l1.b*l2.a) == 0);
}

bool AreSame(Line l1, Line l2) {
    return ((AreParallel(l1, l2)) && (cmp(l1.c*l2.a, l2.c*l1.a) == 0) && (cmp(l1.c*l2.b, l1.b*l2.c) == 0));
}

bool areIntersect(Line l1, Line l2, Point &p) {
    if (AreParallel(l1, l2)) return false;
    ld d = l1.a*l2.b - l2.a*l1.b;
    ld dx = l1.b*l2.c - l2.b*l1.c;
    ld dy = l1.c*l2.a - l2.c*l1.a;
    p = Point(dx / d, dy / d);
    return true;
}

ld distToLine(Point p, Point a, Point b, Point &c) {
    Point ap = p - a, ab = b - a;
    ld k = ap.dot(ab) / ab.Norm();
    c = a + (ab * k);
    return (p - c).len();
}

struct Circle: Point {
    ld r;
    //constructor
    Circle(ld x = 0, ld y = 0, ld r = 0): Point(x, y), r(r) {}
    Circle(Point p, ld r): Point(p), r(r) {}
    bool ContainsPoint(Point A) {
        return ((*this - A).len() <= r + EPS);
    }
};
ld x1, y1, x2, y2, x3, y3, x4, y4;

ld Dist(Point A, Point B) {
    return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

bool IsInSeg(Point tmp, Point A, Point B) {
    return (abs(Dist(A, tmp) + Dist(B, tmp) - Dist(A, B)) <= EPS);
}

ld PointToSegment(Point P, Point A, Point B) {
    Line d(A, B);
    Point tmp;
    ld DtoL = distToLine(P, A, B, tmp);
    ld xx = d.PointWLine(P);
    if (!IsInSeg(tmp, A, B))
        return min(Dist(P, A), Dist(P, B));
    return min(Dist(P, A), min(Dist(P, B), DtoL));
}

ld SegmentToSegment() {
    Point A(x1, y1);
    Point B(x2, y2);
    Point C(x3, y3);
    Point D(x4, y4);
    Line d1(A, B);
    Line d2(C, D);
    Point tmp;
    bool Flag = areIntersect(d1, d2, tmp);
    if (AreSame(d1, d2)) {
        if ((IsInSeg(A, C, D)) || (IsInSeg(B, C, D)) || (IsInSeg(C, A, B)) || (IsInSeg(D, A, B)))
            return 0;
        ld Dist1 = min(Dist(A, C), Dist(A, D));
        ld Dist2 = min(Dist(B, C), Dist(B, D));
        return min(Dist1, Dist2);
    }
    else if ((Flag) && (((IsInSeg(tmp, A, B)) && (IsInSeg(tmp, C, D)))))
        return 0;
    else {
        ld D1ToD2 = min(PointToSegment(A, C, D), PointToSegment(B, C, D));
        ld D2ToD1 = min(PointToSegment(C, A, B), PointToSegment(D, A, B));
        return min(D1ToD2, D2ToD1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("distance5.in", "r", stdin);
    freopen("distance5.out", "w", stdout);
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    cout << fixed << setprecision(10) << SegmentToSegment();
    return 0;
}
