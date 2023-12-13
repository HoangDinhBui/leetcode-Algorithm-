#include <stdio.h>
#include <stdlib.h>
//1287. Element Appearing More Thanh 25% In Sorted Array
int* countSameElement(int sortedArray[], int copSortedArray[], int numOfArray){
	int *count = (int*)malloc(numOfArray * sizeof(int)); 
	for (int i = 0 ; i< numOfArray; i++){
		count[i] = 0;
		for (int j = 0; j < numOfArray; j++){
			if (copSortedArray[i] == sortedArray[j]){
				count[i]++;
			}
		}
	}
	return count;
}
int main(){
	int numOfElement, sortedArray[100];
	printf("Enter the number of element in array: ");
	scanf("%d", &numOfElement);
	printf("Enter the array's element: ");
	for (int i = 0; i < numOfElement; i++){
		scanf("%d", &sortedArray[i]);
	}
	int standarCount = (numOfElement/4);
	int copSortedArray[100];
	for (int i = 0; i < numOfElement; i++){
		copSortedArray[i] = sortedArray[i];
	}
	int *countElement = countSameElement(sortedArray, copSortedArray, numOfElement);
	for (int i = 0 ; i< numOfElement; i++){
		if (countElement[i] > standarCount){
			printf("%d", sortedArray[i]);
			break;
		}
	}
}
