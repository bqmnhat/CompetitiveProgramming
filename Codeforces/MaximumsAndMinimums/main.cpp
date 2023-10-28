#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500010
#define MaxVal 1000000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t, n, a[MaxN+1], lmin[MaxN+1], rmin[MaxN+1], lmax[MaxN+1], rmax[MaxN+1];
vector<int> pos[MaxVal+1], Divisors[MaxVal+1];

void Init() {
    for (int i=1; i<=MaxVal; i++)
        pos[i].clear();
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
}

void FindMinRange() {
    stack<pii> stk;
    for (int i=1; i<=n; i++) {
        while ((!stk.empty()) && (stk.top().first > a[i])) {
            int id = stk.top().second;
            stk.pop();
            rmin[id] = i - 1;
        }
        stk.push(pii(a[i], i));
    }
    while (!stk.empty()) {
        int id = stk.top().second;
        stk.pop();
        rmin[id] = n;
    }
    for (int i=n; i>=1; i--) {
        while ((!stk.empty()) && (stk.top().first > a[i])) {
            int id = stk.top().second;
            stk.pop();
            lmin[id] = i + 1;
        }
        stk.push(pii(a[i], i));
    }
    while (!stk.empty()) {
        int id = stk.top().second;
        stk.pop();
        lmin[id] = 1;
    }
}

void FindMaxRange() {
    stack<pii> stk;
    for (int i=1; i<=n; i++) {
        while ((!stk.empty()) && (stk.top().first < a[i])) {
            int id = stk.top().second;
            stk.pop();
            rmax[id] = i - 1;
        }
        stk.push(pii(a[i], i));
    }
    while (!stk.empty()) {
        int id = stk.top().second;
        stk.pop();
        rmax[id] = n;
    }
    for (int i=n; i>=1; i--) {
        while ((!stk.empty()) && (stk.top().first <= a[i])) {
            int id = stk.top().second;
            stk.pop();
            lmax[id] = i + 1;
        }
        stk.push(pii(a[i], i));
    }
    while (!stk.empty()) {
        int id = stk.top().second;
        stk.pop();
        lmax[id] = 1;
    }
}

void FindDivisors() {
    for (int i=1; i<=MaxVal; i++)
        for (int j=2*i; j<=MaxVal; j+=i)
            Divisors[j].push_back(i);
}

pii Intersection(pii seg1, pii seg2) {
    pii res = pii(-1, -1);
    if (max(seg1.first, seg2.first) <= min(seg1.second, seg2.second))
        res = pii(max(seg1.first, seg2.first), min(seg1.second, seg2.second));
    return res;
}

ll Solution() {
    ll ans = 0, cnt = 0;
    for (int i=1; i<=n+1; i++) {
        for (int d: Divisors[a[i]]) {
            if (pos[d].size() == 0)
                continue;
            ll posd1, posd2;
            posd1 = posd2 = -1;
            if (pos[d][0] < i) {
                int tmp = lower_bound(pos[d].begin(), pos[d].end(), i) - pos[d].begin() - 1;
                posd1 = pos[d][tmp];
            }
            if (pos[d][pos[d].size() - 1] > i) {
                int tmp = upper_bound(pos[d].begin(), pos[d].end(), i) - pos[d].begin();
                posd2 = pos[d][tmp];
            }
            pii LR;
            ll L, R;
            if (posd1 != -1) {
                LR = Intersection(pii(lmin[posd1], rmin[posd1]), pii(lmax[i], rmax[i]));
                L = LR.first, R = LR.second;
                if ((L != -1) && (R != -1) && (posd1 >= L) && (i <= R))
                    ans += (posd1 - L + 1LL)*(R - i + 1LL);
            }
            if (posd2 != -1) {
                LR = Intersection(pii(max(posd1 + 1, 1LL*lmin[posd2]), rmin[posd2]), pii(lmax[i], rmax[i]));
                L = LR.first, R = LR.second;
                if ((L != -1) && (R != -1) && (i >= L) && (posd2 <= R))
                    ans += (i - L + 1LL)*(R - posd2 + 1ll);
            }
        }
        if (a[i] != a[i-1]) {
            ans += (cnt*(cnt+1LL))/2;
            cnt = 0;
        }
        cnt++;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        FindMinRange();
        FindMaxRange();
        cout << Solution() << '\n';
        if (i < t)
            Init();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    FindDivisors();
    Solve();
    return 0;
}
