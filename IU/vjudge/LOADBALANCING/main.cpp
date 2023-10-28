#include <iostream>
#include <bits/stdc++.h>
#define MaxC 5
#define MaxS 10
using namespace std;
int c, s, a[MaxS + 1], sum;
double am;

void ReadData() {
    for (int i=1; i<=s; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

void SolveTestCase() {
    sum = 0;
    ReadData();
    am = double(double(sum)/double(c));
    double Imbalanced = 0;
    for (int i=s+1; i<=2*c; i++)
        a[i] = 0;
    s = 2*c;
    sort(a+1, a+1+s);
    for (int i=1; i<=c; i++) {
        cout << ' ' << i-1 << ':';
        if (a[i] > 0)
            cout << ' ' << a[i];
        if (a[s-i+1] > 0)
            cout << ' ' << a[s-i+1];
        cout << '\n';
        Imbalanced += abs(am - double(a[i] + a[s-i+1]));
    }
    cout << fixed << setprecision(5) << "IMBALANCE = " << Imbalanced << '\n';
}

void Solve() {
    int cnt = 0;
    while (cin >> c >> s) {
        cnt++;
        cout << "Set #" << cnt << '\n';
        SolveTestCase();
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
