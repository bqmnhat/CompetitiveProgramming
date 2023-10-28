#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    bool IsPrime = true;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9I.INP");
    fo.open("BAI9I.OUT");
    fi >> n;
    if (n == 2) {
        fo << "n la so nguyen to";
        return 0;
    }
    for (int i = 2; i <= ceil(sqrt(n)); i++) {
        if (n%i == 0) {
            IsPrime = false;
            break;
        }
    }
    if (IsPrime == false) {
        fo << "n khong la so nguyen to";
    }
    else
        fo << "n la so nguyen to";
    return 0;
}
