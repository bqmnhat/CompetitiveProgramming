#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[1000000],n;

bool IsCP(int x) {
    if (x <= 0) return false;
    int m = sqrt(x);
    return (m*m == x);
}

void LongestCP() {
    int d = 0, tmp = 0;
    int tfi = -1, tla= -1, fimax = -1, lamax = -1;
    for (int i = 1; i<=n; i++) {
        if (IsCP(a[i])) {
            ++d;
            tla = i;
            tfi = tla - d + 1;
            if (d > tmp) {
                tmp = d;
                fimax = tfi;
                lamax = tla;
            }
        }
        else d = 0;
    }
    cout << tmp << endl;
    cout << fimax << " " << lamax;
}

void ReadData(int n, int a[]) {
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SQRSEQ.INP", "r", stdin);
    freopen("SQRSEQ.OUT", "w", stdout);
    cin >> n;
    ReadData(n,a);
    LongestCP();
    return 0;
}
