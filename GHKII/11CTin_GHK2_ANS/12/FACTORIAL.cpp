#include<bits/stdc++.h>
using namespace std;

long long factor(long long k){
    if (k>0) return k*factor(k-1);
    else return 1;
}

int digits(long long k){
    int d = 0;
    while(k>0){
        ++d;
        k = k/10;
    }
    return d;
}

int main(){
    freopen("FACTORIAL.INP","r", stdin);
    freopen("FACTORIAL.OUT","w", stdout);
    int m,n;
    long long a = 0, b = 0;
    cin >> m >>n;
    while(digits(factor(a)) < m){
        a++;
    }
    while(digits(factor(b)) <= n){
        b++;
    }
    if(digits(factor(b)) > n) b--;
    if(digits(factor(a)) > n || digits(factor(b)) > n){
        cout << a << " " << a-1;
    }
    else{
        cout << a << " " << b;
    }
}
