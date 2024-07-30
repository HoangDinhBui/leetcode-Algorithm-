#include <iostream>
using namespace std;
void result()
{
	int n;
	cin >> n;
	if(n>=3 && n <= 28)
	{
		printf("aa%c\n", n-2+96);
	}
	else if(n>=29 && n <= 53)
	{
		printf("a%cz\n", n-27+96);
	}
	else if(n>=53 && n <= 78)
	{
		printf("%czz\n", n-52+96);
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		result();
	}
}