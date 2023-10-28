#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n, t;
ll a[MaxN], sum = 0, sumEven = 0;

void ReadData() {
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[i] % 2 == 0)
            sumEven += a[i];
    }
}

void Query1() {
    cout << '7';
}

void Query2() {
    if (a[0] > a[1])
        cout << "Bigger";
    else if (a[0] < a[1])
        cout << "Smaller";
    else
        cout << "Equal";
}

void Query3() {
    if (((a[0] <= a[1]) && (a[1] <= a[2])) || ((a[2] <= a[1]) && (a[1] <= a[0]))) {
        cout << a[1];
        return;
    }
    if (((a[1] <= a[2]) && (a[2] <= a[0])) || ((a[0] <= a[2]) && (a[2] <= a[1]))) {
        cout << a[2];
        return;
    }
    if (((a[2] <= a[0]) && (a[0] <= a[1])) || ((a[1] <= a[0]) && (a[0] <= a[2]))) {
        cout << a[0];
        return;
    }
}

void Query4() {
    cout << sum;
}

void Query5() {
    cout << sumEven;
}

void Query6() {
    for (int i=0; i<n; i++) {
        a[i] = a[i]%26;
        cout << char(a[i] + 'a');
    }
}

void Query7() {
    int i = 0, cnt = 0;
    while (i < n-1) {
        cnt++;
        if (cnt > n) {
            cout << "Cyclic";
            return;
        }
        i = a[i];
    }
    if (i == n-1)
        cout << "Done";
    if (i >= n)
        cout << "Out";
}

void Solve() {
    switch (t) {
        case 1:
            Query1();
            break;
        case 2:
            Query2();
            break;
        case 3:
            Query3();
            break;
        case 4:
            Query4();
            break;
        case 5:
            Query5();
            break;
        case 6:
            Query6();
            break;
        case 7:
            Query7();
            break;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    ReadData();
    Solve();
    return 0;
}
