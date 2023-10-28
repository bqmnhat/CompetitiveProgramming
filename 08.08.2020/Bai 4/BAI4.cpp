#include <iostream>
#include <fstream>
using namespace std;

bool IsCovered(float a, float b, float r) {
    if ((a>=(2*r)) and (b>=(2*r))) {
        return true;
    }
    else
        return false;
}

int main()
{
    float a,b,r;
    ifstream fi;
    ofstream fo;
    fi.open("BAI4.INP");
    fo.open("BAI4.OUT");
    fi >> a >> b >> r;
    if (IsCovered(a,b,r)) {
        fo << "YES";
    }
    else
        fo << "NO";
    return 0;
}
