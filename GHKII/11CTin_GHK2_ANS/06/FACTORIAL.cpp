#include <bits/stdc++.h>
using namespace std;
long long factorial(int n){
    if(n == 0)
        return 1;
    else
        return n*factorial(n - 1);
}
int numCount(long long n){
    int res = 0;
    while(n != 0){
        n /= 10;
        res++;
    }
    return res;
}
int main(){
    freopen("FACTORIAL.INP", "r", stdin);
    freopen("FACTORIAL.OUT", "w", stdout);
    long long n, m;
    cin >> m >> n;
    long long bd = m, kt = m;
    for(long long i = m; i <= n*n; ++i){
        int t = numCount(factorial(i));
        if(t >= m && t <= n)
            kt++;
        else if(kt != bd){
            kt--;
            break;
        }else{
            kt++;
            bd++;
        }
    }
    if(bd == kt)
        cout << 2 << ' ' << 1;
    else
        cout << bd << ' ' << kt;
}
