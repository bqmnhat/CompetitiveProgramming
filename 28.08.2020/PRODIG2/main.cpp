#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
int a[30];
int top;
void Rev(int a[]) {
    int ans[30];
    int k = 0;
    for (int i = top-1; i >= 0; i--) {
        ans[k] = a[i];
        k = k + 1;
    }
    a[] = ans[30];
}

ll FindM(ll n) {
    ll ans = 0;
    if (n <= 9)
        return 10 + n;
    for (int i = 9; i >= 2; --i) {
        while (n%i == 0) {
            a[top] = i;
            top = top + 1;
            n = n/i;
        }
    }
    Rev(a[]);
    if (n > 1)
        return -1;
    else
        return ans;
}

int main()
{
    long long n;
    ifstream fi;
    ofstream fo;
    fi.open("PRODIG.INP");
    fo.open("PRODIG.OUT");
    fi >> n;
    fo << FindM(n);
    return 0;
}
