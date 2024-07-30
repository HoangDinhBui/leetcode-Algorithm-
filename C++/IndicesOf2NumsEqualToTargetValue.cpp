#include <stdio.h>
#include <stdlib.h>
// 219. Contains Duplicate
//Given an integer array nums and an integer k, return true if there are two distinct 
//indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
int main(){
	int nums[100], target, sizeOfArr;
	printf("Enter the number of element in array: ");
	scanf("%d", &sizeOfArr);
	printf("Enter the array's element: \n");
	for (int i = 0; i < sizeOfArr; i++){
		scanf("%d", &nums[i]);
	}
	printf("Enter the targer number: ");
	scanf("%d", &target);
	for (int i = 0; i < sizeOfArr - 1; i++){
		for (int j = i + 1; j < sizeOfArr; j++){
			if (nums[i] + nums[j] == target){
				printf("%d %d", i, j);
				break;
			}
		}
	}
}