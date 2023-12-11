#include<stdio.h>
void input(int a[], int *n)
{
	for (int i = 0; i < *n; i++)
	{
		scanf("%d", &a[i]);
	}
}
void Sort(int a[], int n)
{
		if(a[0] > a[1])
		{
			int x = a[1];
			for (int j = 1; j < n; j++)
			{
				a[j] = a[j + 1];
				if(j == n -1)
				a[j] = x;
			}
		}
		else if (a[0] < a[1])
		{
			int x = a[0];
			for (int j = 0; j < n; j++)
			{
				a[j] = a[j +1];
				if(j == n -1)
				a[j] = x;
			}
		}
	}
int count(int a[], int n, int k)
{
		int c = 0;
		while (c < k)
		{
				if(a[0] > a[1])
				{
					Sort(a, n);
					c++;
					if ( c == k )
					return a[0];
					else if(a[0] > a[1])
						continue;
					else if(a[0] < a[1])
					{
						c = 0;
						continue;
					}
				}
				else if(a[0] < a[1])
				{
				    Sort(a, n);
				    c++;
				    if ( c == k )
				    return a[0];
				    else if(a[0] < a[1])
				    {
				    	c = 0;
				    }
				} 
		}
}
int main()
{
			int a[100], n, k;
			printf("Enter number of players: ");
			scanf("%d", &n);
			printf("Enter the number of round to win the game: ");
			scanf("%d", &k);
			printf("Enter the player's number: ");
			input(a, &n);
			printf("The winner is: ");
			printf("%d", count(a, n, k));
			
}