#include <iostream>
#include <math.h>
 
using namespace std;
 
void result() {
    int A[5][5], loc1 = 0, loc2 = 0;
    for(int i = 0; i < 5; i++)
    {
    	for(int j = 0; j < 5; j++)
    	{
    		cin >> A[i][j];
    	}
    }
    for(int i = 0; i < 5; i++)
    {
    	for(int j = 0; j < 5; j++)
    	{
    		if(A[i][j] == 1)
    		{
    			loc1 = i;
    			loc2 = j;
    		}
    	}
    }
    cout << abs(2-loc1) + abs(2-loc2) << endl;
}
 
int main() {
    result();
    return 0;
}
