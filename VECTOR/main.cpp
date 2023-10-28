// CPP program to illustrate
// push_back() function
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(6);
	v.push_back(5);

	// Vector becomes 1, 2, 3, 4, 5, 6

	for (int i = 0; i<v.size(); i++)
		cout << v[i] << " "  ;
}
