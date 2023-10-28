#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("FACTORIAL.INP", "r", stdin);
    //freopen("FACTORIAL.OUT", "w", stdout);
    int t, m, n;
    cin >> t;
    if(t == 0){
        cout << 1;
    }
    else{
        for(int i = 1; i <= t; i++)
            t *= i;
        cout << t;
    }
    return 0;
}
