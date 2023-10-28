#include <bits/stdc++.h>

using namespace std;
int a,b,c,x,y;
double khoangcach = 1e9, tam;

void ptrinh(int x1, int y1, int x2, int y2)
{
    int ChiPhuongX, ChiPhuongY;
    ChiPhuongX = x2-x1;
    ChiPhuongY = y2-y1;
    a = -(ChiPhuongY);
    b = ChiPhuongX;
    c = -(a*x1)+b*y1;
    tam = (abs(a*x+b*y+c)/(sqrt(a*a+b*b)));
    if (khoangcach>tam) khoangcach = tam;
}

int main()
{
    freopen("distance.inp","r",stdin);
    freopen("distance.out","w",stdout);
    int n,a[1001],b[1001];
    cin>>n;
    cin>>x>>y;
    for (int i = 0; i<n; i++) cin>>a[i]>>b[i];
    for (int i = 0; i<n-1; i++)
    {
        ptrinh(a[i],b[i],a[i+1],b[i+1]);
    }
    cout<<setprecision(4)<<fixed<<khoangcach;
    return 0;
}
