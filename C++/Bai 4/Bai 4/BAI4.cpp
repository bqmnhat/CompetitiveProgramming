#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
    int n,x = 1,sum = 1;
    ifstream fi;
    ofstream fo;
    fi.open("BAI4.INP");
    fo.open("BAI4.OUT");
    fi >> n;
    while (sum < n) {
        x += 1;
        sum += sqrt(x);
    }
    fo << x;
    fi.close();
    fo.close();
    return 0;
}
