#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, a[9], DayInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void ReadData() {
    string s;
    getline(cin, s);
    int cnt = 0;
    for (int i=0; i<10; i++) {
        if (s[i] != ' ') {
            cnt++;
            a[cnt] = s[i] - '0';
        }
    }
}

bool IsLeap(int year) {
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return true;
    return false;
}

void GetDate(int x[], int& day, int& month, int& year) {
    day = x[1]*10 + x[2];
    month = x[3]*10 + x[4];
    year = x[5]*1000 + x[6]*100 + x[7]*10 + x[8];
}

bool IsEarlier(int x[], int y[]) {
    int dayx, monthx, yearx, dayy, monthy, yeary;
    GetDate(x, dayx, monthx, yearx);
    GetDate(y, dayy, monthy, yeary);
    if (yearx < yeary)
        return true;
    else if (yearx > yeary)
        return false;
    else {
        if (monthx < monthy)
            return true;
        else if (monthx > monthy)
            return false;
        else {
            if (dayx < dayy)
                return true;
            else
                return false;
        }
    }
}

bool IsLegal(int date[]) {
    int day, month, year;
    GetDate(date, day, month, year);
    if (year < 2000)
        return false;
    if ((IsLeap(year)) && (month == 2))
        return ((day <= 29) && (day >= 1));
    return ((month >= 1) && (month <= 12) && (day <= DayInMonth[month]) && (day >= 1));
}

int Solution(int MostEarly[]) {
    int ans = 0;
    sort(a+1, a+9);
    do {
        if (IsLegal(a)) {
            ans++;
            if (IsEarlier(a, MostEarly))
                for (int i=1; i<=8; i++)
                    MostEarly[i] = a[i];
        }
    } while (next_permutation(a+1, a+9));
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        ReadData();
        int MostEarly[9] = {0, 3, 1, 1, 2, 9, 9, 9, 9};
        int ans = Solution(MostEarly);
        cout << ans;
        if (ans != 0) {
            cout << ' ';
            cout << MostEarly[1] << MostEarly[2] << ' ' << MostEarly[3] << MostEarly[4] << ' ';
            for (int i=5; i<=8; i++)
                cout << MostEarly[i];
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    cin.ignore();
    Solve();
    return 0;
}
