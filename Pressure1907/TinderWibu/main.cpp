#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int n, a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

bool IsSameBits(int a, int b) {
    bool visa[10], visb[10];
    memset(visa, false, sizeof(visa));
    memset(visb, false, sizeof(visb));
    while (a > 0) {
        int tmp = a%10;
        visa[tmp] = true;
        a/=10;
    }
    while (b > 0) {
        int tmp = b%10;
        visb[tmp] = true;
        b/=10;
    }
    for (int i=0; i<10; i++)
        if ((visa[i] == true) && (visb[i] == true))
            return true;
    return false;
}

int Solution() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (IsSameBits(a[i], a[j]))
                ans++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
