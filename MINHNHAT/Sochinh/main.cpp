#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[1000001], n = 0;

void ReadData() {
    int k;
    int i = 1;
    while (cin >> k) {
        a[i] = k;
        i++;
    }
    n = i-1;
}

int MainNum(bool &exist) {
    sort(a+1,a+1+n);
    int d = 0;
    exist = false;
    for (int i=1; i<=n; i++) {
        if (a[i] != a[i-1])
            d = 0;
        d +=1;
        if (d > n/2) {
            exist = true;
            return a[i-1];
        }
    }
    return -1;
}

int main()
{
    freopen("Sochinh.INP", "r", stdin);
    freopen("Sochinh.OUT", "w", stdout);
    ReadData();
    bool IsExist;
    int a = MainNum(IsExist);
    if (IsExist == true)
        cout << "YES" << endl << a;
    else
        cout << "NO";
    return 0;
}
