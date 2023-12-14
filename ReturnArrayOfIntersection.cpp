#include <stdio.h>
#include <stdlib.h>
//349. iven two integer arrays nums1 and nums2, return an array of their intersection.
//Each element in the result must be unique and you may return the result in any order.
void input(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &nums[i]);
    }
}
void intersectionArray(int nums1[], int nums2[], int size1, int size2)
{
	int newNums[10];
	if (size2 < size1)
	{
		for(int i = 0; i < size1; i++)
		{
			for(int j = 0; j < size2; j++)
			{
				if (nums2[j] == nums1[i])
				{
					newNums[j] = nums2[j];
				}
			}
		}
		for (int i = 0; i < size2; i++)
		{
			if(newNums[i] != newNums[i + 1])
			{
				printf("%d ", newNums[i]);
			}
			else
				continue;
		}
	}
	else
	{
		for(int i = 0; i < size2; i++)
		{
			for(int j = 0; j < size1; j++)
			{
				if (nums1[i] == nums2[j])
				{
					newNums[i] = nums1[i];
				}
			}
		}
		for (int i = 0; i < size1; i++)
		{
			if(newNums[i] != newNums[i + 1])
			{
				printf("%d ", newNums[i]);
			}
			else
				continue;
		}
	}
}
int main()
{
	int nums1[100], nums2[100], size1, size2;
	printf("Enter the number of 1st array element: ");
	scanf("%d", &size1);
	printf("Enter the array's element: \n");
	input(nums1, size1);
	printf("Enter the number of 2nd array element: ");
	scanf("%d", &size2);
	printf("Enter the array's element: \n");
	input(nums2, size2);
	intersectionArray(nums1, nums2, size1, size2);
}