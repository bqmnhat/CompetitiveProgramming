#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
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

struct Circle: Point {
    ld r;
    //constructor
    Circle(ld x = 0, ld y = 0, ld r = 0): Point(x, y), r(r) {}
    Circle(Point p, ld r): Point(p), r(r) {}
    bool ContainsPoint(Point A) {
        return ((*this - A).len() <= r + EPS);
    }
};

struct Camp {
    Point loc;
    ll r, m;
} a[MaxN+10];
Point work[MaxN+10];
int s, n, d;
bool mark[MaxN+10];

void ReadData() {
    for (int i=1; i<=s; i++) {
        cin >> a[i].loc.x >> a[i].loc.y >> a[i].r >> a[i].m;
        a[i].r += d;
    }
    work[1].x = 0;
    work[1].y = 0;
    for (int i=1; i<=n; i++)
        cin >> work[i+1].x >> work[i+1].y;
    work[n+2] = work[1];
    n += 2;
}

bool IsInSegment(Point P, Point A, Point B) {
    Line d(A, B);
    return ((abs(d.PointWLine(P)) <= EPS) && (P.x - min(A.x, B.x) >= EPS) && (P.x - max(A.x, B.x) <= EPS) && (P.y - min(A.y, B.y) >= EPS) && (P.y - max(A.y, B.y) <= EPS));
}

ld Dist(Point A, Point B) {
    ld dist = sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y));
    return dist;
}

bool IsSegmentInterCircle(Point A, Point B, Point O, ld r) {
    Point tmp;
    ld dist = distToLine(O, A, B, tmp);
    if (!IsInSegment(tmp, A, B))
        dist = min(Dist(O, A), Dist(O, B));
    return (dist - r <= EPS);
}

bool IsInCircle(Point A, Point O, ld r) {
    ld dist = Dist(O, A);
    return (dist - r <= EPS);
}

void MarkAvailable() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=s; j++) {
            if ((IsInCircle(work[i], a[j].loc, a[j].r))
            || ((i > 1) && (IsSegmentInterCircle(work[i], work[i-1], a[j].loc, a[j].r))))
                mark[j] = true;
        }
    }
}

ll Solution() {
    memset(mark, false, sizeof(mark));
    MarkAvailable();
    ll ans = 0;
    for (int i=1; i<=s; i++)
        if (mark[i])
            ans += a[i].m;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("concor.inp", "r", stdin);
    freopen("concor.out", "w", stdout);
    cin >> s >> n >> d;
    ReadData();
    cout << Solution();
    return 0;
}
