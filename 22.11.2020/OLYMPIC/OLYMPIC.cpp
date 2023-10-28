#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long c;
int n;
struct bt {
    int a,b; // a la trinh do can co de lam bai; b la trinh do dat them dc khi hoan thanh bai
} x[100001];

void ReadData() {
    for (int i = 1; i<=n; i++) {
        cin >> x[i].a >> x[i].b;
    }
}

bool CompareVal(bt a, bt b) {
    return(a.a <= b.a);
}

int MaxBt() {
    int ans = 0;
    sort(x+1, x+n+1, CompareVal);
    for (int i = 1; i<=n; i++) {
        if (c >= x[i].a) {
            ans = ans + 1;
            c = c + x[i].b;
        }
        else
            break;
    }
    return ans;
}

int main()
{
    freopen("OLYMPIC.INP", "r", stdin);
    freopen("OLYMPIC.OUT", "w", stdout);
    cin >> n >> c;
    ReadData();
    cout << MaxBt();
    return 0;
}
