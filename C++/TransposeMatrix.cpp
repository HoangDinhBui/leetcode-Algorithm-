#include <stdio.h>
int main(){
	int m, n;
	printf("Enter the Matrix column's number: ");
	scanf("%d", &m);
	printf("Enter the Matrix row's number: ");
	scanf("%d", &n);
	int matrix[100];
	printf("Enter the Matrix: \n");
	for(int j = 0; j < m*n; j++){
		scanf("%d", &matrix[j]);
	}
	printf("The transpose matrix: \n");
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", matrix[j*m+i]);
		}
		printf("\n");
	}
    /*The second way
    int m, n;
	printf("Enter the Matrix column's number: ");
	scanf("%d", &m);
	printf("Enter the Matrix row's number: ");
	scanf("%d", &n);
	int matrix[n][m];
	printf("Enter the Matrix: \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("The transpose matrix: \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", matrix[j][i]);
		}
		printf("\n");
	}*/
}