#include <bits/stdc++.h>
using namespace std;

#define INPFILE "FACTORIAL.INP"
#define OUTFILE "FACTORIAL.OUT"

using ld = long double;
using i64 = long long int;

#define ALL(v) v.begin(),v.end()
#define len(v) (i64((v).size()))
#define MP(a,b) (make_pair((a),(b)))
#define sqr(x) ((x)*(x))
#define between(l,x,r) ((l) <= (x) && (x) <= (r))

const int MAX_FACT_LENGTH = 3e5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen(INPFILE, "r", stdin);
    freopen(OUTFILE, "w", stdout);

    vector<ld> log10_Fact(MAX_FACT_LENGTH + 1);

    log10_Fact[0] = log10_Fact[1] = log10(1);

    for (int i = 2; i <= MAX_FACT_LENGTH; i++) {
        log10_Fact[i] = log10_Fact[i-1] + log10(i);
    }

    i64 M, N; cin >> M >> N;

    vector<i64> FactLength(MAX_FACT_LENGTH + 1);

    for (int i = 0; i <= MAX_FACT_LENGTH; i++) {
        i64 thisFactLength = floor(log10_Fact[i]) + 1;
        FactLength[i] = thisFactLength;
    }

    i64 a = -1, b = -1;

    for (int i = 0; i <= MAX_FACT_LENGTH; i++) {
        if (FactLength[i] >= M) {
            a = i;
            break;
        }
    }

    for (int i = 0; i <= MAX_FACT_LENGTH; i++) {
        if (FactLength[i] > N) {
            b = i - 1;
            break;
        }
    }

    cout << a << ' ' << b;
}
