#include <bits/stdc++.h>
using namespace std;

struct Cor{
    int x;
    int y;
};

double mindisp2p(int x, int y, Cor a[], int n)
{
    double ans=999999999, tg; Cor vec;
    for(int i=0;i<n;i++)
    {
        vec.x=x-a[i].x;
        vec.y=y-a[i].y;
        tg=sqrt(vec.x*vec.x+vec.y*vec.y);
        if(ans>tg) ans=tg;
    }
    return ans;
}

double mindisp2e(int x, int y, Cor a[], int n)
{
    Cor AB, BE, AE; double ans, finans=999999999, tg; int x1, x2, y1, y2, AB_BE, AB_AE, j;
    for(int i=0;i<n;i++)
    {
        if(i==n-1) j=0;
        else j=i+1;
        AB.x=a[j].x-a[i].x;
        AB.y=a[j].y-a[i].y;
        BE.x=x-a[j].x;
        BE.y=y-a[j].y;
        AE.x=x-a[i].x;
        AE.y=y-a[i].y;
        AB_BE=AB.x*BE.x+AB.y*BE.y;
        AB_AE=AB.x*AE.x+AB.y*AE.y;
        if(AB_BE>0)
            ans=sqrt((x-a[j].x)*(x-a[j].x)+(y-a[j].y)*(y-a[j].y));
        else if(AB_AE<0)
            ans=sqrt((x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y));
        else
        {
            x1=a[j].x-a[i].x;
            y1=a[j].y-a[i].y;
            x2=x-a[i].x;
            y2=y-a[i].y;
            tg=sqrt(x1*x1+y1*y1);
            ans=abs(x1*y2-y1*x2)/tg;
        }
        if(finans>ans) finans=ans;
    }
    return finans;
}

int main()
{
    freopen("DISTANCE.inp","r",stdin);
    freopen("DISTANCE.out","w",stdout);
    int n, x, y; Cor a[1000];
    cin >> n >> x >> y;
    for(int i=0;i<n;i++)
        cin >> a[i].x >> a[i].y;
    cout << setprecision(4) << fixed << mindisp2e(x,y,a,n);
}
