#include <iostream>
#include <fstream>
using namespace std;

bool IsCovered(float a1, float b1, float a2, float b2) {
    if (((a1>=a2) and (b1>=b2)) or ((a1>=b2) and (b1>=a2))) {
        return true;
    }
    else
        return false;
}

int main()
{
    float a1,b1,a2,b2;
    ifstream fi;
    ofstream fo;
    fi.open("BAI5.INP");
    fo.open("BAI5.OUT");
    fi >> a1 >> b1 >> a2 >> b2;
    if (IsCovered(a1,b1,a2,b2)) {
        fo << "YES";
    }
    else
        fo << "NO";
    return 0;
}
