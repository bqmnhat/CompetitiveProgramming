#include <bits/stdc++.h>
#include <cmath>
using namespace std;

double n,a,b,c,d;
double x,y,z;
double little,temp;

//Distance = sqrt (abs(abs(a-b)-(abs(c-d))

int main()
{
    freopen("DISTANCE.inp","r",stdin);
    freopen("DISTANCE.out","w",stdout);
    cin>>n;
    cin>>a>>b;
    little = 0;
    x=abs(a-b);
    for(int i=0;i<n;i++)
    {
        cin>>c>>d;
        y = abs(c-d);
        z = sqrt(abs(x-y));
        if (z >= little)
        {
            little = z;
        }
    }
    temp = round(little * 10000);
    little = temp/10000;

    cout<<little;
    return 0;

}
