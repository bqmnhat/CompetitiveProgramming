#include <bits/stdc++.h>
using namespace std;

#define INPFILE "DISTANCE.INP"
#define OUTFILE "DISTANCE.OUT"

using ld = long double;
using i64 = long long int;
using pld = pair<ld,ld>;

#define ALL(v) v.begin(),v.end()
#define len(v) (int((v).size()))
#define MP(a,b) (make_pair((a),(b)))
#define sqr(x) ((x)*(x))
#define between(l,x,r) ((l) <= (x) && (x) <= (r))

const ld EPS = 1e-9;

ld distSquared(pld A, pld B) {
    ld dX = A.first - B.first;
    ld dY = A.second - B.second;
    return sqr(dX) + sqr(dY);
}

ld crossProd(pld A, pld B) {
    return A.first * B.second - A.second * B.first;
}

bool isStraightLine(pld A, pld B, pld C) {
    ld crossEval = (B.first - A.first) * (C.second - A.second);
    crossEval -= (B.second - A.second) * (C.first - A.first);

    return abs(crossEval) <= EPS;
}

bool isOnSegment(pld Q, pld A, pld B) {
    bool straightLine = isStraightLine(Q, A, B);

    if (!straightLine) return false;

    bool xBetween = between(A.first, Q.first, B.first) || between(B.first, Q.first, A.first);
    bool yBetween = between(A.second, Q.second, B.second) || between(B.second, Q.second, A.second);

    return xBetween && yBetween;
}

// return distance from point to segment, everything squared
ld distSquared_PointToSegment(pld Q, pld A, pld B) {
    if (isOnSegment(Q, A, B)) return 0;

    pld U1 = A;
    pld U2 = MP(B.first - A.first, B.second - A.second);

    pld U3 = Q;
    pld U4 = MP(-U2.second, U2.first);

    ld t = crossProd(U3, U4) - crossProd(U4, U1);
    t /= crossProd(U4, U2);

    pld H(0, 0);
    H.first = U1.first + t * U2.first;
    H.second = U1.second + t * U2.second;

    if (isOnSegment(H, A, B)) {
        return distSquared(Q, H);
    }

    ld res1 = distSquared(Q, A);
    ld res2 = distSquared(Q, B);

    return min(res1, res2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen(INPFILE, "r", stdin);
    freopen(OUTFILE, "w", stdout);

    int N; cin >> N;
    vector<pld> P(N);

    for (int i = 0; i < N; i++) {
        ld x, y; cin >> x >> y;
        P[i] = {x,y};
    }

    pld Q; cin >> Q.first >> Q.second;

    ld res1 = distSquared(Q, P[0]);

    for (int i = 0; i < N; i++) {
        ld thisEval = distSquared(Q, P[i]);
        res1 = min(thisEval, res1);
    }

    ld res2 = res1;

    for (int i = 0; i < N; i++) {
        pld A = P[i % N];
        pld B = P[(i+1) % N];
        ld thisEval = distSquared_PointToSegment(Q, A, B);
        res2 = min(thisEval, res2);
    }

    ld res = sqrtl(min(res1, res2));

    cout << fixed << setprecision(4) << res;
}
