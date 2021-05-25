//DoA Assignment5       max min using Divide and Conquer
#include <stdio.h>

struct pair
{
    int min;
    int max;
};

struct pair getMinMax(int ray[], int low, int high)
{
    struct pair minmax, mml, mmr;
    int mid;
    
    if(low == high)             //if there is only one element
    {
        minmax.max = ray[low];
        minmax.min = ray[low];
        return minmax;
    }
    if(high == low + 1)         //if there are two elements
    {
        if(ray[low] > ray[high])
        {
            minmax.max = ray[low];
            minmax.min = ray[high];
        }
        else
        {
            minmax.max = ray[high];
            minmax.min = ray[low];
        }
        return minmax;
    }                           //if there are more than two elements
    mid = (low + high) / 2;
    mml = getMinMax(ray, low, mid);
    mmr = getMinMax(ray, mid+1, high);
    
    if(mml.min < mmr.min)       //compare minimums of two parts
        minmax.min = mml.min;
    else
        minmax.min = mmr.min;
    
    if(mml.max > mmr.max)       //compare maximums of two parts
        minmax.max = mmr.max;
    else
        minmax.max = mmr.max;
    return minmax;
}

int main()
{
    int num;
    printf("Enter number of elements: ");
    scanf("%d",&num);
    int ray[num];
    printf("Enter elements: ");
    for(int i = 0; i < num; i++)
        scanf("%d",&ray[i]);
    struct pair minmax = getMinMax(ray, 0, num-1);
    printf("Maximum element is %d\n",minmax.max);
    printf("Minmum element is %d\n",minmax.min);
    getchar();
}
