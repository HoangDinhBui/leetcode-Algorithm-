#include <stdio.h>
//70. Climbing stair
int main()
{
    int stepNum1 = 1;
    int stepNum2 = 2;
    int numOfSideStep;
    printf("Enter the number of sidestep: ");
    scanf("%d", &numOfSideStep);
    if(numOfSideStep <= 2)
    {
        printf("%d", numOfSideStep);
        return 0;
    }
    int dp[numOfSideStep];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= numOfSideStep; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];//the next step is equal to the 1st previous step and 2nd previous step
    }
    printf("The number of way to go up stair: %d", dp[numOfSideStep - 1]);
}