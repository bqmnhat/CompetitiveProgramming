#include <bits/stdc++.h>
using namespace std;

#define INPFILE "BUG.INP"
#define OUTFILE "BUG.OUT"

using ld = long double;
using i64 = long long int;
using pii = pair<i64,i64>;

#define ALL(v) v.begin(),v.end()
#define len(v) (int((v).size()))
#define MP(a,b) (make_pair((a),(b)))
#define sqr(x) ((x)*(x))
#define between(l,x,r) ((l) <= (x) && (x) <= (r))

const i64 INF = 1e16;

const int MAX_N = 10000;

pii P[MAX_N];

int N;

inline i64 evalIfPoint_X() {
    i64 res = INF;

    for (int i = 0; i < N; i++) {
        i64 thisEval = 0;
        int c = 1;

        for (int j = i-1; j >= 0; j--, c++) {
            i64 targetX = P[i].first - c;
            thisEval += abs(P[j].first - targetX);
        }

        c = 1;

        for (int j = i+1; j < N; j++, c++) {
            i64 targetX = P[i].first + c;
            thisEval += abs(P[j].first - targetX);
        }

        res = min(res, thisEval);
    }

    return res;
}

inline i64 evalIfPoint_Y(const i64& targetY) {
    i64 res = 0;

    for (int i = 0; i < N; i++) {
        res += abs(P[i].second - targetY);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen(INPFILE, "r", stdin);
    freopen(OUTFILE, "w", stdout);

    cin >> N;

    i64 sumY = 0;

    for (int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
        sumY += P[i].second;
    }

    sort(P, P + N);

    i64 res = INF;

    for (i64 d = -1; d <= 1; d++) {
        i64 targetY = (sumY / N) + d;
        res = min(res, evalIfPoint_Y(targetY));
    }

    i64 resAdder = evalIfPoint_X();

    cout << res + resAdder;
}
