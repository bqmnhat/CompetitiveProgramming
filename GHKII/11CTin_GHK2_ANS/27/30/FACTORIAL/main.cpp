#include <iostream>
#include <cmath>

using namespace std;

double a,b;

int cd(long long n)
{
    return floor(log10(n))+1;

}

int main(){
int n,m;
cin>>n>>m;
long long a=1;b=1;
int digits =1 ;
while (cd(b)<n)
{
    digits *= 10;
    b *= digits;
    while (cd(b)>m){
        a *=10;
        b/= 10;
    }
}
cout<<a<<" "<<b-1<<endl;
return 0;
}
