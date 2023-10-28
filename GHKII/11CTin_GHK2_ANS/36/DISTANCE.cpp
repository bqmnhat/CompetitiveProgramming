#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double n,a,b,c,d;
double x,y,z;
double dnat;
int main()
{
    freopen("DISTANCE.INP","r",stdin);
    freopen("DISTANCE.OUT","w",stdout);
    cin>>n;
    cin>>a>>b;
    x=abs(a-b);
    dnat=0;
    for(int i=0;i<n;i++){
        cin>>c>>d;
        y=abs(c-d);
        z=sqrt(abs(x-y));
        if(z>dnat){
            dnat=z;
        }
    }
    cout<<setprecision(5)<<dnat;
    return 0;
}
