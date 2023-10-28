#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 1500000
long long n, st[MaxN+1];

void BuildST() {
    st[1] = 1;
    for (long long i=2; i<=MaxN; i++) {
        long long PreEd = st[i-1]+(i-1)*(i-2);
        st[i] = ((PreEd /i)+1)*i;
    }
}

long long Solution() {
    long long d = 0, c = 0;
    while (c + (d+1) < n) {
        d++;
        c = c + d;
    }
    d++;
    c++;
    long long ans = st[d]+(n-c)*d;
    return ans;
}

int main()
{
    freopen("SEQUENCE.INP", "r", stdin);
    freopen("SEQUENCE.OUT", "w", stdout);
    BuildST();
    cin >> n;
    cout << Solution();
    return 0;
}
