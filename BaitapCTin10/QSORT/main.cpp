#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn = 1e5 + 1;
int n, a[maxn];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void PrintAns() {
    for (int i=1; i<=n; i++)
        cout << a[i] << " ";
}

int Ptt(int lo, int hi)  {
    int pi = a[hi], i = (lo-1);
    for (int j = lo; j < hi; j++)
    {
        if (a[j] < pi)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1], a[hi]);
    return (i+1);
}

void Qsort(int lo, int hi) {
    if (lo < hi) {
        int pi = Ptt(lo,hi);
        Qsort(lo, pi-1);
        Qsort(pi+1, hi);
    }
}

int main()
{
    freopen("QS.INP", "r", stdin);
    freopen("QS.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Qsort(1,n);
    PrintAns();
    return 0;
}
