#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
typedef long double ld;
typedef long long ll;
const ld Pi = acos(-1);
const ld EPS = 1e-9;

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
        return (a*_A.x + b*_A.y + c);
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

ld DistPToP(Point A, Point B) {
    return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
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

bool IsInSeg(Point P, Point A, Point B) {
    Line d(A, B);
    return ((d.PointWLine(P) == 0) && (P.x <= max(A.x, B.x) + EPS) &&
    (P.x >= min(A.x, B.x) + EPS) && (P.y <= max(A.y, B.y) + EPS) && (P.y >= min(A.y, B.y) + EPS));
}

ld DistPointToSeg(Point P, Point A, Point B) {
    Point tmp;
    ld Dist = distToLine(P, A, B, tmp);
    if (IsInSeg(tmp, A, B))
        return Dist;
    return min(DistPToP(P, A), DistPToP(P, B));
}

int n;
Point p, a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].x >> a[i].y;
}

ld Solution() {
    ld ans = 1e18;
    for (int i=1; i<=n; i++)
        ans = min(ans, DistPointToSeg(p, a[i], a[i%n+1]));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p.x >> p.y;
    ReadData();
    cout << fixed << setprecision(4) << Solution();
    return 0;
}
