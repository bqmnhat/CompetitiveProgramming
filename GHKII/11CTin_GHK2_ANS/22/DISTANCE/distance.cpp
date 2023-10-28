#include <bits/stdc++.h>
using namespace std;

int x, y;
double kq=1e9, temp;

void distance (int x1, int y1, int x2, int y2)
{
    int a = -(y2-y1);
    int b = x2 - x1;
    int c = -(a*x1)+b*y1;
    temp = (abs(a*x+b*y+c)/(sqrt(a*a+b*b)));
    if (kq > temp)
        kq = temp;
}

int main()
{
    freopen("distance.inp","r",stdin);
    freopen("distance.out","w",stdout);

    int n,k[10000],l[10000];
    cin >> n;
    cin >> x >> y;
    for (int i=0;i<n;i++)
        cin >> k[i] >> l[i];
    for (int i=0;i<n-1;i++)
    {
        distance(k[i],l[i],k[i+1],l[i+1]);
    }
    cout << setprecision(4) << fixed << kq;
}
