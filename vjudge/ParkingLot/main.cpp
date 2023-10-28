#include <iostream>
#include <bits/stdc++.h>
#define MaxN 30
using namespace std;
typedef long long ll;
ll n, a[MaxN+1] = {0, 0, 0, 24, 132, 672, 3264, 15360, 70656, 319488, 1425408, 6291456, 27525120, 119537664, 515899392, 2214592512, 9462349824, 40265318400, 170724950016, 721554505728, 3040836845568, 12781822672896, 53601191854080, 224300372066304, 936783906865152, 3905465301860352, 16255179905040384, 67553994410557440, 280349076803813376, 1161928703861587968, 4809844402031689728};

ll Cal(ll n) {
    ll Pow4 = 1;
    for (int i=1; i<=n-3; i++)
        Pow4 *= 4;
    ll ans = 24*Pow4 + 36*(Pow4/4)*(n-3);
    return ans;
}

void Gen() {
    for (int i=3; i<=MaxN; i++)
        a[i] = Cal(i);
    for (int i=0; i<=MaxN; i++)
        cout << a[i] << ", ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << a[n];
    //Gen();
    return 0;
}
