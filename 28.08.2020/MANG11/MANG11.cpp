#include <iostream>
#include <cstdio>
using namespace std;
int a[100];

bool IsPalin(int a[], int x, int y) { // x: start pos; y: ending pos
    int m = int((x+y)/2), i = x, j = y;
    while (i<j) {
        if (a[i] != a[j])
            return false;
        i += 1;
        j = j - 1;
    }
    return true;
}

void ReadData(int a[], int n) {
    for (int i = 1; i<=n; i++)
        cin >> a[i];
}

int Solve(int a[], int n) {
    int ans = 0, l = 0;
    for (int i = 1; i<=n-1; i++) {
        for (int j = i+1; j<=n; j++) {
            if (IsPalin(a,i,j)) {
                l = j-i+1;
                if (l > ans)
                    ans = l;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    freopen("MANG11.INP", "r", stdin);
    freopen("MANG11.OUT", "w", stdout);
    cin >> n;
    ReadData(a,n);
    cout << Solve(a,n);
    return 0;
}
