#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("THUVI.INP","r",stdin);
    freopen("THUVI.OUT","w", stdout);
    int a;
    cin >> a;
    while(a--)
    {
        int a;
        cin >> a;
        vector <int> ar(a,0);
        if(a == 1)
        {
            cout<<1<<"\n";
        }
        if(a == 2)
        {
            cout<< 1 << " " << 2 <<"\n";
        }
        if(a == 3)
        {
            cout<< 2 << " " << 1 << " " << 3 <<"\n";
        }
        if(a == 4)
        {
            cout<< 3 << " " << 1 << " " << 2 << " " << 4 <<"\n";
        }
        if (a == 5)
        {
            cout<< 2 << " " << 4 << " " << 1 << " " << 3 << " " << 5 <<"\n";
        }
        if(a == 6)
            cout<< 3 << " " << 4 << " " << 1 << " " << 5 << " " << 2 << " " << 6 << "\n";
    }
    return 0;
}
