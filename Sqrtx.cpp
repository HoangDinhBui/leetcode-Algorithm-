//not allow using sqrt(x) or pow(x, 0.5)
#include <stdio.h>
int main()
{
    int num;
    printf("Enter the number that you need to square: ");
    scanf("%d", &num);
    if(num == 0)
        printf("%d", 0);
    if(num == 1)
        printf("%d", 1);
    if(num < 0)
        return 0;
    int result = 1;
    while(result * result <= num)
    {
        result++;
    }
    result--;
    printf("%d", result);
}