#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k;
long long a[100001];

long long GCD(int a, int b) {
    int tmp;
    while (b>0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

long long MaxGCD() {
    for (int i=1; i<=n-k+1; i++) {

    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
