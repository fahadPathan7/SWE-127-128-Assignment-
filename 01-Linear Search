/*
Problem statement :
find the largest and smallest data from a data set . (using linear search)
*/

#include <stdio.h>

int main()
{
    int n, i, max, min;

    printf ("Enter the size of the array : ");
    scanf("%d", &n);
    int ar[n];

    printf ("Enter elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }

   max = min = ar[0];

    for (i = 1; i < n; i++)
    {
        if (ar[i] < min)
        {
            min = ar[i];
        }
        if (ar[i] > max)
        {
            max = ar[i];
        }
    }

    printf("\nMaximum value is = %d\n", max);
    printf("Minimum value is = %d\n\n", min);
}



