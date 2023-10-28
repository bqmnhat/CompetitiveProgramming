#include <iostream>
#include <bits/stdc++.h>
#define MaxN xxxxx
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
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

struct Circle: Point {
    ld r;
    //constructor
    Circle(ld x = 0, ld y = 0, ld r = 0): Point(x, y), r(r) {}
    Circle(Point p, ld r): Point(p), r(r) {}
    bool ContainsPoint(Point A) {
        return ((*this - A).len() <= r + EPS);
    }
};
int n, m;
vector<pii> vtx, ps;

void ReadData() {
    vtx.push_back(pii(0, 0));
    for (int i=1; i<=n; i++) {
        ll x, y;
        cin >> x >> y;
        vtx.push_back(pii(x, y));
    }
    ps.push_back(pii(0, 0));
    for (int i=1; i<=m; i++) {
        ll x, y;
        cin >> x >> y;
        ps.push_back(pii(x, y));
    }
}

ld Dist(Point A, Point B) {
    return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

bool IsInSegment(ld xp, ld yp, ll x1, ll y1, ll x2, ll y2) {
    Point P(xp, yp);
    Point A(x1, y1);
    Point B(x2, y2);
    Line d(A, B);
    return ((abs(d.PointWLine(P)) <= EPS) && (xp >= min(x1, x2)) && (xp <= max(x1, x2)) && (yp >= min(y1, y2)) && (yp <= max(y1, y2)));
}

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

int orientation(Point p, Point q, Point r)
{
    ll val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

void CheckPointWithPolygon() {
    for (int i=1; i<=m; i++) {
        int cnt2 = 0, cnt3 = 0, cnt4 = 0;
        ll xp = ps[i].first, yp = ps[i].second;
        bool Boundary = false;
        Point PrevTmp(-1e12, -1e12);
        Point P1(xp, yp);
        Point P2(1532425254, 2424343443);
        Point P3(2453535134, 1567567534);
        Point P4(2086543174, -2443434534);
        for (int j=1; j<=n; j++) {
            if ((ps[i] == vtx[j]) || (IsInSegment(xp, yp, vtx[j].first, vtx[j].second, vtx[(j%n)+1].first, vtx[(j%n)+1].second))) {
                cout << "BOUNDARY\n";
                Boundary = true;
                break;
            }
            Point A(vtx[j].first, vtx[j].second);
            Point B(vtx[(j%n)+1].first, vtx[(j%n)+1].second);
            Line d(A, B);
            Line dp(P1, P2);
            Point tmp;
            bool IsIntersect = areIntersect(d, dp, tmp);
            if ((IsIntersect) && (doIntersect(P1, P2, A, B)))
                cnt2++;
            if ((IsIntersect) && (doIntersect(P1, P3, A, B)))
                cnt3++;
            if ((IsIntersect) && (doIntersect(P1, P4, A, B)))
                cnt4++;
        }
        if (!Boundary) {
            int cntInside = 0, cntOutside = 0;
            if (cnt2&1)
                cntInside++;
            else
                cntOutside++;
            if (cnt3&1)
                cntInside++;
            else
                cntOutside++;
            if (cnt4&1)
                cntInside++;
            else
                cntOutside++;
            if (cntInside > cntOutside)
                cout << "INSIDE\n";
            else
                cout << "OUTSIDE\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    CheckPointWithPolygon();
    return 0;
}
