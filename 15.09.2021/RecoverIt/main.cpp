#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, p[200001], maxDiv[2750133], lp = 0;
bool Sieve[2750133];
multiset <int, greater<int>> b;

void MakeSieve() {
    int m = sqrt(2750132);
    Sieve[1] = Sieve[0] = true;
    for (int i=2; i<=m; i++) {
        if (Sieve[i] == false) {
            for (int j=i; j <= 2750132/i; j++)
                Sieve[i*j] = true;
        }
    }
    for (int i=2; i<=2750132; i++) {
        if (Sieve[i] == false) {
            lp++;
            p[lp] = i;
        }
    }
}

int MaxDivisor(int x) {
    int m = sqrt(x), ans = 1;
    for (int i=2; i<=m; i++) {
        if (x%i == 0) {
            if (x/i > ans)
                ans = x/i;
            return ans;
        }
    }
    return ans;
}

void MakeMaxDiv() {
    for (int i=1; i<= 2750132; i++) {
        if (Sieve[i])
            maxDiv[i] = MaxDivisor(i);
    }
}

void ReadData() {
    int bi;
    for (int i=1; i<=2*n; i++) {
        cin >> bi;
        b.insert(bi);
    }
}

int BinSearch(int val) {
    int l=1, r = lp;
    while (l <= r) {
        int m = (l+r)/2;
        if (p[m] == val) {
            return m;
        }
        else if (p[m] < val)
            l = m+1;
        else
            r = m-1;
    }
}

void Solve() {
    while (!b.empty()) {
        int u = *b.begin();
        multiset<int, greater<int>> :: iterator it;
        it = b.begin();
        if (Sieve[u] == false) {
            int m = BinSearch(u);
            multiset<int, greater<int>> :: iterator itm;
            itm = b.find(m);
            cout << m << " ";
            b.erase(it);
            b.erase(itm);
        }
        else {
            cout << u << " ";
            b.erase(it);
            multiset<int, greater<int>> :: iterator it2;
            it2 = b.find(maxDiv[u]);
            b.erase(it2);
        }
    }
}

int main()
{
    cin >> n;
    ReadData();
    MakeSieve();
    MakeMaxDiv();
    Solve();
    return 0;
}
