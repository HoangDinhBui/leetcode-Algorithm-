#include <stdio.h>
void input(int nums[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }
}
void printIntersection(int nums1[], int nums2[], int size1, int size2) {
    int maxSize = (size1 < size2) ? size1 : size2;
    int newNums[100];  // Assuming a maximum size of 100 for the result array

    int k = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (nums1[i] == nums2[j]) {
                newNums[k++] = nums1[i];
                break;  // Break to ensure uniqueness
            }
        }
    }
    for (int i = 0; i < k; i++) {
        printf("%d ", newNums[i]);
    }
}
int main() {
    int nums1[100], nums2[100], size1, size2;
    printf("Enter the number of elements for the 1st array: ");
    scanf("%d", &size1);
    printf("Enter the elements for the 1st array:\n");
    input(nums1, size1);
    printf("Enter the number of elements for the 2nd array: ");
    scanf("%d", &size2);
    printf("Enter the elements for the 2nd array:\n");
    input(nums2, size2);
    printf("Intersection of the two arrays: ");
    printIntersection(nums1, nums2, size1, size2);
    return 0;
}
