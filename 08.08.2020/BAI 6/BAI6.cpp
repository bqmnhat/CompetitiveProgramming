#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    float r1,c1,r2,c2;
    ifstream fi;
    ofstream fo;
    fi.open("BAI6.INP");
    fo.open("BAI6.OUT");
    fi >> r1 >> c1 >> r2 >> c2;
    if (r1*(c2/c1) > r2)
        fo << 1;
    else
        fo << 2;
    return 0;
}
