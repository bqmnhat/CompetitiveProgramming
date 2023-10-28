#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200005
using namespace std;
int t, n, x, Sieve[MaxN+1];

void MakeSieve() {
    for (int i=2; i*i<=MaxN; i++)
        if (!Sieve[i])
            for (int j=i; i*j<=MaxN; j++)
                Sieve[i*j] = i;
}

vector<int> Factorize(int alpha) { // actually we don't need to Factorize in O(nlogn), this is just for revision because the O(sqrt(n)) method is so easy
    vector<int> res;
    while (alpha>1) {
        int p = Sieve[alpha];
        if (p == 0)
            p = alpha;
        res.push_back(p);
        alpha /= p;
    }
    return res;
}

void SolveTestCase() {
    if (n%x != 0) {
        cout << "-1\n";
        return;
    }
    vector<int> tmp = Factorize(n/x);
    sort(tmp.begin(), tmp.end());
    vector<int> ShiftedLeft;
    ShiftedLeft.push_back(x);
    int tmpval = x;
    for (int alpha: tmp) {
        tmpval *= alpha;
        ShiftedLeft.push_back(tmpval);
    }
    int l = ShiftedLeft.size(), cur = 2;
    for (int i=0; i<l; i++) {
        cout << ShiftedLeft[i] << ' ';
        for (; cur < ShiftedLeft[i]; cur++)
            cout << cur << ' ';
        cur = ShiftedLeft[i]+1;
    }
    cout << 1 << '\n';
}

void Solve() {
    MakeSieve();
    for (int i=1; i<=t; i++) {
        cin >> n >> x;
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
