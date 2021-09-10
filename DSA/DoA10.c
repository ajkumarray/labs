//  DoA Assignment10      0-1 knapsack problem

#include <stdio.h>

struct Item         //structure for an item which stores weight and corresponding value of Item
{
    int value, weight;
};

void printItem(struct Item ray[], int num)      //function to print Items of list
{
    for(int i = 0; i < num; i++)
    {
        printf("Value%d = %d and weight%d = %d\n", (i+1), ray[i].value, (i+1), ray[i].weight);
    }
}

int max(int a, int b)       //function returns maximum of two integers
{
    return (a > b) ? a : b;
}

int knapsack(struct Item ray[], int weight, int num)        //function to find the maximum value that can be put in a knapsack of capacity weight
{
    int temp[num + 1][weight + 1];
    for(int i = 0; i <= num; i++)
    {
        for(int w = 0; w <= weight; w++)
        {
            if(i == 0 || w == 0)
                temp[i][w] = 0;
            else
                if(ray[i - 1].weight <= weight)
                    temp[i][w] = max(ray[i - 1].value + temp[i - 1][w - ray[i - 1].weight], temp[i - 1][w]);
            else
                temp[i][w] = temp[i - 1][w];
        }
    }
    return temp[num][weight];
}

int main(int argc, const char * argv[]) {
    int num;                        //number of items
    int weight;                     //max weight knapsack can hold
    printf("Enter number of items and max weight knapsack can hold: ");
    scanf("%d %d", &num, &weight);
    
    struct Item ray[num];
    for(int i = 0; i < num; i++)    //reading values and weight of Items
    {
        printf("Enter value and weight of Item %d: ",i+1);
        scanf("%d %d", &ray[i].value, &ray[i].weight);
    }
    printf("Entered Item list:\n");
    printItem(ray, num);            //printing entered Items
    int finalValue = knapsack(ray, weight, num);    //knapsack function call
    printf("Maximum value we can obtain = %d\n", finalValue);
    
    return 0;
}
