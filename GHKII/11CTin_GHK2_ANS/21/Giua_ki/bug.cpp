#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[10001],b[10001];
    cin>>n;
    int tongx = 0, tongy = 0, demx, demy;
    for (int i = 0; i<n; i++)
    {
        cin>>a[i]>>b[i];
        tongx +=a[i];
        tongy +=b[i];
    }
    int diemdenx = (tongx/n), diemdeny = (tongy/n);
    for (int i = 0; i<n; i++)
    {
        demx = diemdenx - a[i];
        demy = diemdeny -b[i];
    }
    cout<<demx+demy;
    return 0;
}
