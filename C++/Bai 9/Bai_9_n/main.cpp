#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9N.INP");
    fo.open("BAI9N.OUT");
    fi >> n;
    n = "0" + n + "0";
    int found = (int)n.find("0",1);
    int pfound = 0, c = 0;
    while (found != 0) {
        if (found - pfound > 1) {
            c = c + 1;
        }
        pfound = found;
        found = (int)n.find("0", pfound + 1);
    }
    fo << c;
    return 0;
}
