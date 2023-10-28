#include <iostream>
#include <bits/stdc++.h>
#define MaxC 26
#define MaxN 200000
using namespace std;
int t, n, p, cnt[MaxC+1], sum = 0;
bool BePrinted[MaxN+1];
string s;

void InitCnt() {
    for (int i=1; i<=MaxC; i++)
        cnt[i] = 0;
}

void Count() {
    for (int i=0; i<n; i++) {
        cnt[s[i] - 'a' + 1]++;
        sum += (s[i] - 'a' + 1);
    }
}

void CalDeletion() {
    int i = 26;
    while ((sum > p) && (i >= 1)) {
        while ((cnt[i] == 0) && (i >= 1))
            i--;
        if (i == 0)
            break;
        sum -= i;
        cnt[i]--;
    }
}

void InitBePrinted() {
    for (int i=0; i<n; i++)
        BePrinted[i] = false;
}

void SolveTestCase() {
    InitCnt();
    sum = 0;
    Count();
    CalDeletion();
    InitBePrinted();
    for (int i=0; i<n; i++) {
        if (cnt[s[i] - 'a' + 1] > 0) {
            cnt[s[i] - 'a' + 1]--;
            BePrinted[i] = true;
        }
    }
    for (int i=0; i<n; i++)
        if (BePrinted[i])
            cout << s[i];
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s >> p;
        n = s.length();
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
