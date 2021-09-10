//  rodCutting

#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int rodCutting(int value[], int n)
{
    int tempVal[n + 1];
    tempVal[0] = 0;
    int i, j;
    for(i = 1; i <= n; i++)
    {
        int maxVal = INT_MIN;
        for(j = 0; j < i; j++)
            maxVal = max(maxVal, value[j] + tempVal[i - j - 1]);
        tempVal[i] = maxVal;
    }
    return tempVal[n];
}

int main(int argc, const char * argv[]) {
    int n;
    printf("Enter length of the rod: ");
    scanf("%d", &n);
    int value[n];
    printf("Enter price of pieces: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &value[i]);
    printf("Maximum value obtained is %d\n", rodCutting(value, n));
    return 0;
}
