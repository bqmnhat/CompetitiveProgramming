#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, p[3], m[3], s[3];

void CountTime(int lead, int pmm, int mm, int pss, int ss) {
    int mplus = mm - pmm, splus = ss - pss;
    if (pss > ss) {
        splus = 60 - pss + ss;
        mplus--;
    }
    s[lead] = s[lead] + splus;
    if (s[lead] > 59) {
        s[lead] = s[lead]%60;
        m[lead]++;
    }
    m[lead] = m[lead] + mplus;
}

void PrintAns() {
    for (int i=1; i<=2; i++) {
        if (m[i] < 10)
            cout << "0";
        cout << m[i] << ":";
        if (s[i] < 10)
            cout << "0";
        cout << s[i] << '\n';
    }
}

void Solve() {
    int Leading = 0, k, pmm = 0, mm, pss = 0, ss;
    char c;
    for (int i=1; i<=n; i++) {
        cin >> k >> mm >> c >> ss;
        CountTime(Leading, pmm, mm, pss, ss);
        pmm = mm;
        pss = ss;
        if (p[k]+1 > p[Leading]) {
            Leading = k;
        }
        else if (p[k]+1 == p[Leading])
            Leading = 0;
        p[k]++;
    }
    mm = 48;
    ss = 0;
    CountTime(Leading, pmm, mm, pss, ss);
    PrintAns();
}

int main()
{
    freopen("BASKET.INP", "r", stdin);
    freopen("BASKET.OUT", "w", stdout);
    cin >> n;
    Solve();
    return 0;
}
