#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int GT(int x){
    int giaithua=1;
    for(int i=1;i<=x;i++){
        giaithua=giaithua*i;
    }
    return giaithua;
}
int sochuso(int x){
    int cnt=1;
    if(x<10){
        return cnt=1;
    }
    while(x>=10){
        cnt=cnt+1;
        x=x/10;
    }
    return cnt;
}
int main(){
    freopen("FACTORIAL.INP","r",stdin);
    freopen("FACTORIAL.OUT","w",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=m;i<=n*1000000;i++){
            if(sochuso(GT(i))==m){
                cout<<i<<" ";
                break;
            }
        }
        for(int i=m;i<=n*1000000;i++){
            if(sochuso(GT(i))==n){
                cout<<i;
                break;
            }
        }
}
