#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s, ans[10000001];
int a[9], n, k = 0;

void ChangeData() {
    for (int i=0; i<s.length(); i++) {
        a[i] = s[i] - 'a' + 1;
    }
    n = s.length();
    sort(a, a+n);
}

void Reverse(int x) {
    int i = x, j = n-1;
    while (i<j) {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

void StoreData() {
    k++;
    for (int i=0; i<n; i++) {
        ans[k] = ans[k] + char(a[i] + 'a' - 1);
    }
}

void PrintAns() {
    for (int i=1; i<=k; i++) {
        cout << ans[i] << endl;
    }
}

bool NextStr() {
    int i = n-1,j = n-1;
    while ((a[i]>=a[i+1]) && (i>=0)) {
        i--;
    }
    while ((a[j]<=a[i]) && (j>=0)) {
        j--;
    }
    if (i < 0)
        return false;
    swap(a[i], a[j]);
    Reverse(i+1);
    return true;
}

void Solve() {
    while (NextStr()) {
        StoreData();
    }
    cout << k << endl;
    PrintAns();
}

int main()
{
    freopen("GENSTR.INP", "r", stdin);
    freopen("GENSTR.OUT", "w", stdout);
    cin >> s;
    ChangeData();
    StoreData();
    Solve();
    return 0;
}
