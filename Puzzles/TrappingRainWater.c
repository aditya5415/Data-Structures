/*
Given n non-negative integers representing an elevation map where the 
width of each bar is 1, compute how much water it is able to trap after 
raining.
*/

#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

int min(int num1, int num2)
{
    return (num1 > num2) ? num2 : num1;
}

int findWater(int arr[], int n)
{
    /* left[i] contains height of tallest bar to the right of i'th bar
    including itself */
    int left[n];

    /* right[i] contains height of tallest bar to the right of i'th bar 
   including itself */
    int right[n];

    int water = 0;

    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }
}

int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum water that can be accumulate is %d ", findWater(arr, n));

    return 0;
}