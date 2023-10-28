#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
bool IsPrime(long long n) {
    if (n == 2) {
        return true;
    }
    for (long long i = 2; i<=ceil(sqrt(n)); i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    long long n;
    int d;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9K.INP");
    fo.open("BAI9K.OUT");
    fi >> n;
    int i = 2;
    while (n>1) {
        if (IsPrime(i) == true) {
            d = 0;
            while (n%i==0) {
                d = d + 1;
                n = n/i;
            }
            if (d != 0) {
                fo << i;
                if (d > 1)
                    fo << "^" << d;
                if (n>1)
                    fo << "*";
            }
        }
        i++;
    }
    return 0;

}
