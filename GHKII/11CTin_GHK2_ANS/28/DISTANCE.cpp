#include <bits/stdc++.h>
using namespace std;
struct line{
int a,b,c;
};
struct point{
int x,y;
};
double dist(int x,int y ,int a , int b, int c){
double res = abs(x*a+ y*b +c)/sqrt(a*a+b*b);
return res;
}
line createLine(int x1, int y1, int x2, int y2){
line tl;
tl.a = y1 - y2;
tl.b = x2 - x1;
tl.c = tl.a*x1 - tl.b*y1;
return tl;
}

int main()
{
    freopen("DISTANCE.INP","r",stdin);
    freopen("DISTANCE.OUT","w",stdout);
    int n;
    double MIN= 10000000;
    point diem,a[10000];
    cin >> n >> diem.x >> diem.y;
        for(int i = 1; i<=n; i++)
                cin >> a[i].x >> a[i].y;
        for(int i =1; i<n; i++)
        for(int j=i+1; j<=n; j++){
            line tam=createLine(a[i].x,a[i].y,a[j].x,a[j].y);
            MIN =  min(MIN,dist(diem.x,diem.y,tam.a,tam.b,tam.c));

        }
cout << fixed << setprecision(4) << MIN;
    return 0;
}
