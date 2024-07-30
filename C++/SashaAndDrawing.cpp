#include <iostream>
 
using namespace std;
 
void result()
{
	int n, k;
	cin >> n >> k;
	int maxCeil = 4*n - 2;
	if(k == maxCeil)
	{
		cout << n*2 << endl;
	}
	else if(k % 2 == 0)
		cout << k/2 << endl;
	else
		cout << k/2 + 1<< endl;
}
 
int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		result();
	}
    return 0;
}