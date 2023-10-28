#include <iostream>

using namespace std;

int main()
{
    freopen("CSC.INP", "w", stdout);
    int limit = 1e4;
    cout << limit << " 2 10\n";
    for (int i=0; i<limit; i++)
        cout << i*2 << ' ';
    return 0;
}
