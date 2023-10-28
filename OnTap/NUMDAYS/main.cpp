#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dd1, mm1, yy1, dd2, mm2, yy2;
int days[13];

void InitDays() {
    days[2] = 28;
    days[4] = days[6] = days[9] = days[11] = 30;
    days[1] = days[3] = days[5] = days[7] = days[8] = days[10] = days[12] = 31;
}

bool Nhuan(int year) {
    return (((year%100 != 0)&&(year%4 == 0)) || (year%400 == 0));
}

void ProcessYear(int &ans) {
    for (int i=yy1; i<yy2; i++) {
        if (Nhuan(i) == true)
            ans += 366;
        else
            ans += 365;
    }
}

void ProcessMonth(int &ans) {
    int tmp = 0;
    for (int i=1; i<mm1; i++) {
        if ((i == 2) && (Nhuan(yy1))) {
            tmp += 1;
        }
        tmp += days[i];
    }
    ans = ans - tmp;
    tmp = 0;
    for (int i = 1; i<mm2; i++) {
        if ((i == 2) && (Nhuan(yy2))) {
            tmp+=1;
        }
        tmp += days[i];
    }
    ans += tmp;
}

void ProcessDay(int &ans) {
    if (Nhuan(yy1) == true)
        days[2] = 29;
    ans = ans - dd1 + 1;
    if (Nhuan(yy2) == true)
        days[2] = 29;
    ans = ans + dd2;
}

int TimeLength() {
    int ans = 0;
    ProcessYear(ans);
    ProcessMonth(ans);
    ProcessDay(ans);
    return ans;
}

int main()
{
    freopen("NUMDAYS.INP", "r", stdin);
    freopen("NUMDAYS.OUT", "w", stdout);
    cin >> dd1 >> mm1 >> yy1 >> dd2 >> mm2 >> yy2;
    InitDays();
    cout << TimeLength();
    return 0;
}
