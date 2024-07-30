#include <stdio.h>
#define SIZE 2

void input(int arr[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void output(int arr[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void sortArr(int one_way[SIZE*SIZE]) {
    for(int i = 0; i < SIZE * SIZE - 1; i++) {
        for(int j = i + 1; j < SIZE * SIZE; j++) {
            if(one_way[i] > one_way[j]) {
                int tmp = one_way[i];
                one_way[i] = one_way[j];
                one_way[j] = tmp;
            }
        }
    }
}

int main()
{
    int arr[SIZE][SIZE];
    input(arr);
    
    int one_way[SIZE*SIZE];
    int index = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            one_way[index] = arr[i][j];
            index++;
        }
    }
    
    sortArr(one_way);
    
    arr[0][0] = one_way[3];
    arr[0][1] = one_way[0];
    arr[1][0] = one_way[2];
    arr[1][1] = one_way[1];
    
    printf("After Sorted:\n");
    output(arr);
    
    return 0;
}