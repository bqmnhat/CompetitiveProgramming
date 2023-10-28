#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int x[100000];
int y[100000];

void ReadData(int a[], int b[], int n) {
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
}

int CountR(int a[], int b[], int n) {
    int ans = 0;
    for (int i = 3; i<=n; i++) {
        if ((x[i-1] > x[i-2]) && (y[i] < y[i-1])) {
            ans = ans + 1;
        }
        if ((y[i-1] > y[i-2]) && (x[i] > x[i-1])) {
            ans = ans + 1;
        }
        if ((y[i-1] < y[i-2]) && (x[i] < x[i-1])) {
            ans = ans + 1;
        }
        if ((x[i-1] < x[i-2]) && (y[i] > y[i-1])) {
            ans = ans + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    cin >> n;
    ReadData(x,y,n);
    cout << CountR(x,y,n);
    return 0;
}
