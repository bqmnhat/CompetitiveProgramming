#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[10000001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

bool IsPalin() {
    int i = 1, j = n;
    while (i <= j) {
        if (a[i] != a[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    cin >> n;
    ReadData();
    if (!IsPalin())
        cout << "FALSE";
    else
        cout << "TRUE";
    return 0;
}
