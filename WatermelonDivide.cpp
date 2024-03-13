#include <iostream>
 
using namespace std;
 
void result()
{
	int n;
	cin >> n;
	if(n%2 == 0 && n > 2)
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
}
int main()
{
	result();
}