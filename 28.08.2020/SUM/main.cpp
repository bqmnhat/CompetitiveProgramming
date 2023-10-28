#include <iostream>
#include <cstdio>
using namespace std;

int SumSeq(int n) {
    return (n*(n+1))/2;
}

int main()
{
    int n;
    freopen("SUM.INP", "r", stdin);
    freopen("SUM.OUT", "w", stdout);
    cin >> n;
    cout << SumSeq(n);
    return 0;
}
