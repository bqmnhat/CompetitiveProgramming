#include <iostream>
#include <cstdio>
using namespace std;
int a[1000000];

int LongestRun(int a[], int n) {
    int ans = 0;
    int l = 0;
    for (int i = 1; i<=n; i++) {
        l = l + 1;
        if (a[i] > a[i+1]) {
            if (l > ans)
                ans = l;
            l = 0;
        }
    }
    return ans;
}

void ReadData(int a[], int n) {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

int main()
{
    int n;
    freopen("MANG08.INP", "r", stdin);
    freopen("MANG08.OUT", "w", stdout);
    cin >> n;
    ReadData(a,n);
    cout << LongestRun(a,n);
    return 0;
}
