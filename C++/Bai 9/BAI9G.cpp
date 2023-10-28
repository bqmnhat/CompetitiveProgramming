#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long long n,c = 0;
    bool ok = true;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9G.INP");
    fo.open("BAI9G.OUT");
    fi >> n;
    while (n>9) {
        if ((n%10) < ((n%100)/10)) {
            ok = false;
            break;
        }
        n = n/100;
    }
    if (ok == false) {
        fo << "cac chu so cua n khong co thu tu tang dan";
    }
    else
        fo << "cac chu so cua n co thu tu tang dan";
    return 0;
}
