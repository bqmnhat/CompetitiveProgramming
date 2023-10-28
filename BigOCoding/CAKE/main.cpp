#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[1000001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int Solution() {
    sort(a+1, a+1+n);
    int ans = n, i = 1, j = n/2 + 1, m = n/2;
    while ((i <= m) && (j <= n))   {
        if (a[i]*2 <= a[j]) {
            ans--;
            i++;
            j++;
        }
        else
            j++;
    }
    return ans;
}

int main()
{
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
