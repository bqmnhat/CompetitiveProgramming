#include <iostream>

using namespace std;

int main()
{
    bool ans = !(1 && !(0 || 1));
    if (ans == true)
        cout << "True";
    else
        cout << "False";
    return 0;
}
