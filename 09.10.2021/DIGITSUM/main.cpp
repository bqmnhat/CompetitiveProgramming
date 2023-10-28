#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T,n;
long long a[21], pow10[21];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void FindMin(int &Min1, int &Min2, int &ID1, int &ID2) {
    Min1 = 10, Min2 = 10, ID1 = 0, ID2 = 0;
    for (int i=1; i<=n; i++) {
        if ((a[i] < Min1) && (a[i] != 0)){
            Min2 = Min1;
            ID2 = ID1;
            Min1 = a[i];
            ID1 = i;
        }
        else if ((a[i] < Min2) && (a[i] != 0)) {
            Min2 = a[i];
            ID2 = i;
        }
    }
}

long long Solution() {
    long long Num1 = 0, Num2 = 0;
    int i = 1, j, Min1, Min2, Min1ID, Min2ID;
    FindMin(Min1, Min2, Min1ID, Min2ID);
    Num1 = Num1*10 + Min1;
    Num2 = Num2*10 + Min2;
    a[Min1ID] = a[Min2ID] = 0;
    sort(a+1, a+1+n);
    i = j = 2;
    while ((i < n) && (j < n)) {
        if (j < i) {
            j = i+1;
            Num2 = Num2*10 + a[j];
        }
        else if (i <= j) {
            i = j+1;
            Num1 = Num1*10 + a[i];
        }
    }
    return Num1 + Num2;
}

void Solve() {
    for (int i=1; i<=T; i++) {
        cin >> n;
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    freopen("DIGITSUM.INP", "r", stdin);
    freopen("DIGITSUM.OUT", "w", stdout);
    cin >> T;
    Solve();
    return 0;
}
