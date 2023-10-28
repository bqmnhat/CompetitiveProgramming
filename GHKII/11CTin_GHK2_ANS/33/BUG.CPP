#include<bits/stdc++.h>
using namespace std;
int n,x[20000] = {0},y[20000]={0},a,b;
double tbX,tbY;
long long sumX = 0, sumY = 0;
int xi,yi;

int sumsth(int n)
{
    long long sum =0 ;
    for(int i=1;i<=n;i++) sum += i;
    return sum;
}
void findTB()
{

    double minDistX = 100000, minDistY = 100000;
    for(int i=1;i<=n;i++)
    {
        if(abs(double(y[i])-tbY) < minDistY)
        {
            minDistY = abs(double(y[i])-tbY);
            yi = i;
        }
        if(abs(double(x[i])-tbX) < minDistX)
        {
            minDistX = abs(double(x[i])-tbX);
            xi = i;
        }
    }

}
int main()
{
    freopen("BUG.INP","r",stdin);
    freopen("BUG.OUT","w",stdout);
    cin>>n;
    int minX=100000,minY=100000;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        x[i] = a;
        y[i] = b;
        sumX += a;
        sumY += b;
        minX = min(minX,a);
        minY = min(minY,b);
    }
    tbX = double(sumX) / n;
    tbY = double(sumY) / n;
    findTB();
    long long moves = 0;
    for(int i=1;i<=n;i++)
    {
        moves += abs(x[i]-minX);
        moves += abs(y[yi]-y[i]);
    }
    moves = moves - sumsth(n-1);

    cout<<moves;
}

