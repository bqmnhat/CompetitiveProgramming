#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int n;
string s;
vector<int> a, b, c;

void SplitData() {
    reverse(s.begin(), s.end());
    int cn = n - 1;
    a.assign(n, 0);
    b.assign(n, 0);
    c.assign(cn, 0);
    for (int i=0; i<cn; i++)
        c[i] = (s[i] - '0');
}

void Solve() {
    int cn = n - 1;
    for (int i = 0; i<cn; i++) {
        if (c[i] == 1) {
            int j = i;
            while (c[j] == 1)
                j++;
            a[j] = 1;
            b[i] = 1;
            i = j;
        }
    }
    while (a.size() < n)
        a.push_back(0);
    while (b.size() < n)
        b.push_back(0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int x: a)
        cout << x;
    cout << '\n';
    for (int x: b)
        cout << x;
}

void PrintAns(int a, int b) {
    vector<int> ansa, ansb;
    ansa.clear();
    ansb.clear();
    while (a > 0) {
        ansa.push_back((a&1));
        a >>= 1;
    }
    while (b > 0) {
        ansb.push_back((b&1));
        b >>= 1;
    }
    while (ansa.size() < n)
        ansa.push_back(0);
    while (ansb.size() < n)
        ansb.push_back(0);
    reverse(ansa.begin(), ansa.end());
    reverse(ansb.begin(), ansb.end());
    for (int x: ansa)
        cout << x;
    cout << '\n';
    for (int y: ansb)
        cout << y;
    cout << '\n';
}

void SolveSub1() {
    n--;
    int c = 0;
    reverse(s.begin(), s.end());
    for (int i=0; i<n; i++)
        c |= ((s[i] - '0')*(1 << i));
    n++;
    for (int a = 0; a<(1 << n); a++) {
        if (a < c)
            continue;
        int b = a - c;
        if ((!(a&b)) && (__builtin_popcount(b) == __builtin_popcount(a))) {
            PrintAns(a, b);
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    if (n <= 15)
        SolveSub1();
    else {
        SplitData();
        Solve();
    }
    return 0;
}
