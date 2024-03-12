#include <iostream>
using namespace std;
void result()
{
	int n;
	cin >> n;
	int *A = new int[n];
	for(int i = 0; i < n; i++)
		cin >> A[i];
	int max = A[0], min = A[0];
	for(int i = 1; i < n; i++)
	{
		if(A[i] > max)
			max = A[i];
		if(A[i] < min)
			min = A[i];
	}
	cout << max - min << endl;
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