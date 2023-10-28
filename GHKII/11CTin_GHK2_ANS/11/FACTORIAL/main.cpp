#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

ll factor (ll k){

    if (k>0) {
        return k*factor(k-1);

    }
    else return 1;
}
int digits (ll k) {
    int j=0;
    while (k>0){
        ++j;
        k=k/10;
    }
    return j;
}



int main()
{

    freopen("FACTORIAL.INP","r",stdin);
    freopen("FACTORIAL.OUT","w",stdout);
    int m,n;
    ll a=0,b=0;
    cin>>m>>n;

    while (digits(factor(a))< m){
       a++;
    }
    while (digits(factor(b))<= n){
        b++;
    }
    if (digits(factor(b)>n)) b--;

    if (digits(factor(a)) > n || digits(factor(b))> n) {
        cout<<a<<" "<<a-1;
    }
    else
        cout<<a<<" "<<b;

    return 0;
}
