#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[1000000];

void ReadData(int a[], int n) {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

bool IsCP(int a) {
    if (a == 0)
        return false;
    if (int(sqrt(a)) * int(sqrt(a)) == a) {
        return true;
    }
    return false;
}

int LongestSeq(int a[], int n) {
    int ans = 0;
    int l = 0;
    for (int i = 1; i<=n; i++) {
        if (IsCP(a[i])) {
            l = l + 1;
        }
        else {
            if (l > ans)
                ans = l;
            l = 0;
        }
    }
    if (l > ans)
        ans = l;
    return ans;
}

int main()
{
    int n;
    freopen("MANG09.INP", "r", stdin);
    freopen("MANG09.OUT", "w", stdout);
    cin >> n;
    ReadData(a,n);
    cout << LongestSeq(a,n);
    return 0;
}
