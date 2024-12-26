#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("THUVI.INP", "r", stdin);
    freopen("THUVI.OUT", "w", stdout);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> ar;
        ar.assign(n,0);
        if(n==1){
            cout<<1<<"\n";
        }
        if(n==2){
            cout<<1<<" "<<2<<"\n";
        }
        if(n==3){
            cout<<2<<" "<<1<<" "<<3<<"\n";
        }
        if(n==4){
            cout<<"3 1 2 4 \n";
        }
        if(n==5){
            cout<<"2 4 1 3 5 \n";
        }
        if(n==6){
            cout<<"3 4 1 5 2 6 \n";
        }
        if(n==7){
            cout<<"4 2 5 1 6 3 7 \n";
        }
    }
    return 0;
}
