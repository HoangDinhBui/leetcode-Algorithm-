#include <stdio.h>
#define SIZE 2

typedef struct {
    int val;
    int originalCol;
    int originalRow;
} element;

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

void sortArr(element one_way[SIZE*SIZE]) {
    for(int i = 0; i < SIZE * SIZE - 1; i++) {
        for(int j = i + 1; j < SIZE * SIZE; j++) {
            if(one_way[i].val > one_way[j].val) {
                element tmp = one_way[i];
                one_way[i] = one_way[j];
                one_way[j] = tmp;
            }
        }
    }
}

void printIndex(element sortedArr[SIZE*SIZE], int arr[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            for(int k = 0; k < SIZE * SIZE; k++) {
                if(arr[i][j] == sortedArr[k].val) {
                    printf("Value: %d - new position: (%d %d) - original position: (%d %d)\n",
                    sortedArr[k].val, i, j, sortedArr[k].originalRow, sortedArr[k].originalCol);
                    break;
                }
            }
        }
    }
}

int main() {
    int arr[SIZE][SIZE];
    input(arr);
    
    printf("Before Sorted: \n");
    output(arr);

    element one_way[SIZE*SIZE];
    int index = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            one_way[index].val = arr[i][j];
            one_way[index].originalRow = i;
            one_way[index].originalCol = j;
            index++;
        }
    }
    
    sortArr(one_way);
    
    arr[0][0] = one_way[3].val;
    arr[0][1] = one_way[0].val;
    arr[1][0] = one_way[2].val;
    arr[1][1] = one_way[1].val;
    
    printf("After Sorted:\n");
    output(arr);
    
    printIndex(one_way, arr);

    return 0;
}