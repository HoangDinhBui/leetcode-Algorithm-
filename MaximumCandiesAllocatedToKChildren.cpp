#include<stdio.h>
//2226. Maximum Candies Allocated to K Children
void inputCandies(int candies[], int length) {
    for (int i = 0; i < length; i++) {
        scanf("%d", &candies[i]);
    }
}
int MaximumCandies(int candies[], int length, int k) {
    int max = candies[0];
    for (int i = 1; i < length; i++) {
        if (candies[i] > max) {
            max = candies[i];
        }
    }
    for (int i = 1; i <= max; i++) {
        int count = 0;
        for (int j = 0; j < length; j++) {
            count += candies[j] / i;
        }
        if (count >= k) {
            return i;
        }
    }
    return 0;
}
int main() {
    int candies[100], length, k;
    scanf("%d", &length);
    inputCandies(candies, length);
    scanf("%d", &k);
    printf("Maximum candies allocated to %d children: %d", k, MaximumCandies(candies, length, k));
    return 0;
}