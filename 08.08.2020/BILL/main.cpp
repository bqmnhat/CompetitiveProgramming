#include <iostream>
#include <fstream>
using namespace std;
ifstream fi;
ofstream fo;

long long Cost(long long n) {
    long long tmp = 0, x = n;
    if (x > 400) {
        tmp = tmp + (x - 400)*20;
        x = 400;
    }
    long long k = ((int)(x-1)/100 * 100 + 1);
    while (k > 100){
        tmp = tmp + (x-k+1)*(14 + k/100 + 1);
        x = k-1;
        k = k - 100;
    }
    k = ((int)(x-1)/50 * 50 + 1);
    while (k > 0) {
        tmp = tmp + (x-k+1)*(14 + k/50);
        x = k - 1;
        k = k - 50;
    }
    return tmp;
}

int main()
{
    long long n;
    fi.open("BILL.INP");
    fo.open("BILL.OUT");
    fi >> n;
    fo << Cost(n);
    return 0;
}
