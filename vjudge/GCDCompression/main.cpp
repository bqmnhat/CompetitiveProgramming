#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int t, n, a[2*MaxN+5], d[2*MaxN+5];
vector<int> cntMod[2*MaxN+5];
vector<int> primes;

void MakeSieve() {
    for (int i=2; i*i<=MaxN; i++)
        if (d[i] == 0)
            for (int j=i; i*j<=MaxN; j++)
                d[i*j] = i;
    for (int i=2; i<=MaxN; i++)
        if (d[i] == 0)
            primes.push_back(i);
}

/*vector<int> PrimeFactors(int val) {
    vector<int> ans;
    unordered_map<int, bool> check;
    ans.clear();
    while (val > 1) {
        int p = d[val];
        if (p == 0)
            p = val;
        if (check.find(p) == check.end()) {
            ans.push_back(p);
            check[p] = true;
        }
        val /= p;
    }
    return ans;
}*/

void ReadData() {
    for (int i=1; i<=2*n; i++)
        cin >> a[i];
}

void SolveTestCase() {
    for (int p: primes) {
        for (int i=0; i<=2*MaxN; i++)
            cntMod[i].clear();
        for (int i=1; i<=2*n; i++)
            cntMod[a[i]%p].push_back(i);
        int cnt = 0;
        for (int i=0; 2*i<=p; i++) {
            int TheOther = (p - i)%p;
            if (i == TheOther)
                cnt += (cntMod[i].size() >> 1);
            else
                cnt += min(cntMod[i].size(), cntMod[TheOther].size());
        }
        if (cnt < n-1)
            continue;
        else {
            int cntcout = 0;
            for (int i=0; 2*i<=p; i++) {
                int TheOther = (p - i)%p, CoutAmount = 0;
                if (i == TheOther)
                    CoutAmount = (cntMod[i].size() >> 1);
                else
                    CoutAmount = min(cntMod[i].size(), cntMod[TheOther].size());
                CoutAmount = min(CoutAmount, n-1-cntcout);
                for (int j=1; j<=CoutAmount; j++) {
                    cout << cntMod[i].back() << ' ';
                    cntMod[i].pop_back();
                    cout << cntMod[TheOther].back() << '\n';
                    cntMod[TheOther].pop_back();
                }
                cntcout += CoutAmount;
                if (cntcout >= n-1)
                    break;
            }
            return;
        }
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeSieve();
    cin >> t;
    Solve();
    return 0;
}
